#include "Croupier.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"
#include "HandEvaluator.h"

Croupier::Croupier(Board& board, std::vector<std::unique_ptr<Player>> &players, std::unique_ptr<DeckImpl> &deck)
    : board_(board), players_(players), deck_(std::move(deck)) {}

void Croupier::dealCardsToPlayers()
{
    for (auto& player : players_)
    {
        deck_->dealCardsToPlayer(player);
        spdlog::info("Dealt hand to player {}: {}", player->getName(), player->showHand());
    }
    board_.pot_ = 1.5; //SB + BB in the pot from the beginning
}

void Croupier::dealFlopCards()
{
    deck_->dealFlopCards(board_);
    spdlog::info("Dealt FLOP: {}{}{}", board_.flop_.at(0), board_.flop_.at(1), board_.flop_.at(2));
}

void Croupier::dealTurnCards()
{
    deck_->dealTurnCards(board_);
    spdlog::info("Dealt TURN: {}", board_.turn_);
}

void Croupier::dealRiverCards()
{
    deck_->dealRiverCards(board_);
    spdlog::info("Dealt RIVER: {}", board_.river_);
}

void Croupier::askPlayers(float bb)
{
    while (!playersToAct_.empty() && (activePlayers()+allInPlayers() > 1))
    {
        Player* playerToAct = playersToAct_.front();
        playersToAct_.pop();
        const std::unique_ptr<Move> playerMove = playerToAct->makeMove(bb);

        if (playerMove->isRaise() || playerMove->isBet())
        {
            for (auto& player : hypotheticalPlayers_ToAct_)
                playersToAct_.push(player);

            hypotheticalPlayers_ToAct_.clear();
            bb = playerToAct->betSize();
        }

        if (!playerMove->isFold())
        {
            hypotheticalPlayers_ToAct_.push_back(playerToAct);
            board_.pot_ += playerMove->moveSize();
        }
    }

    hypotheticalPlayers_ToAct_.clear();
}

size_t Croupier::activePlayers()
{
    auto active = [](const std::unique_ptr<Player>& player) { return player->isActive(); };
    return std::count_if(players_.begin(), players_.end(), active);
}

size_t Croupier::allInPlayers()
{
    auto isAllin = [](const std::unique_ptr<Player>& player){ return player->getStackSize() <= 0; };
    return std::count_if(players_.begin(), players_.end(), isAllin);
}

void Croupier::initializeSbAndBb(Position sb, Position bb)
{
    auto isSbPlayer = [&sb](const std::unique_ptr<Player>& player){ return player->getPosition() == sb; };
    auto isBbPlayer = [&bb](const std::unique_ptr<Player>& player){ return player->getPosition() == bb; };

    auto sbPlayer = std::find_if(players_.begin(), players_.end(), isSbPlayer);
    auto bbPlayer = std::find_if(players_.begin(), players_.end(), isBbPlayer);

    if (sbPlayer == players_.end() || bbPlayer == players_.end())
    {
        spdlog::error("Cannot initialize SB and BB player!");
        throw NoPlayerFoundError();
    }

    spdlog::debug("{} is small blind on position {}", (*sbPlayer)->getName(), (*sbPlayer)->getPosition());
    spdlog::debug("{} is big blind on position {}", (*bbPlayer)->getName(), (*bbPlayer)->getPosition());
    (*sbPlayer)->setSbBetSize();
    (*bbPlayer)->setBbBetSize();
}

void Croupier::evaluateHands(const std::vector<Player*>& players)
{
    HandStrength theBestHand;
    std::vector<Player*> winners;

    for (auto pl : players)
    {
        HandStrength currentHand = HandEvaluator::getInstance().getHandStrength(pl->getHand(), board_.flop_, board_.turn_, board_.river_);
        spdlog::info("{} shows: {}", pl->getName(), currentHand);

        if (currentHand == theBestHand)
            winners.push_back(pl);
        else if (currentHand > theBestHand) //we can have multiple winners
        {
            theBestHand = currentHand;
            winners.clear();
            winners.push_back(pl);
        }
    }

    for (auto pl : winners)
    {
        pl->adjustStack(board_.pot_ / winners.size());
        spdlog::info("{} won the pot: {}", pl->getName(), board_.pot_ / winners.size());
    }
}

void Croupier::chooseWinner()
{
    spdlog::debug("End of hand. Choosing winner...");
    auto isActiveOrAllin = [](const std::unique_ptr<Player>& player) { return player->isActive() || player->getStackSize() <= 0; };

    if (allInPlayers() + activePlayers() >= 2) //we have at least 2 players to choose winner
    {
        std::vector<Player*> toEvaluate;
        for (const auto& ptr : players_)
        {
            if (isActiveOrAllin(ptr))
                toEvaluate.push_back(ptr.get());
        }
        spdlog::info("Hand played to showdown. Evaluating players hands...");
        return evaluateHands(toEvaluate);
    }

    auto winner = std::find_if(players_.begin(), players_.end(), isActiveOrAllin); // here we have only one player, rest have folded

    if (winner == players_.end())   //there is no allin player nor active one!
        throw NoActivePlayerFoundError();

    (*winner)->adjustStack(board_.pot_);
    spdlog::info("Hand finished before showdown. {} won the pot: {}", (*winner)->getName(), board_.pot_);
}

void Croupier::preparePreFlopPlayersToAct()
{
    spdlog::debug("Preparing pre flop players to act...");
    auto isEpPlayer = [](const std::unique_ptr<Player>& player){ return player->getPosition() == Position::EP; };
    auto firstPlayer = std::find_if(players_.begin(), players_.end(), isEpPlayer);

    if (firstPlayer == players_.end()) //there is no EP player so we have less than 4 players
    {
        auto isBuPlayer = [](const std::unique_ptr<Player>& player){ return player->getPosition() == Position::BU; };
        firstPlayer = std::find_if(players_.begin(), players_.end(), isBuPlayer);

        if (firstPlayer == players_.end()) //there is no BU player, this is abnormal situation
        {
            spdlog::error("Cannot find Button player!");
            throw NoPlayerFoundError();
        }

        if (players_.size() == 3)
            initializeSbAndBb(Position::SB, Position::BB);
        else //we have 2 players
            initializeSbAndBb(Position::BU, Position::SB);
    }
    else
        initializeSbAndBb(Position::SB, Position::BB);

    spdlog::debug("First player to act is {} on position {}", (*firstPlayer)->getName(), (*firstPlayer)->getPosition());
    playersToAct_.push(firstPlayer->get());
    auto nextPlayer = firstPlayer+1;

    while (nextPlayer != firstPlayer)
    {
        if (nextPlayer == players_.end())
        {
            nextPlayer = players_.begin();
            continue;
        }
        spdlog::debug("Next player to act is {} on position {}", (*nextPlayer)->getName(), (*nextPlayer)->getPosition());
        playersToAct_.push(nextPlayer->get());
        ++nextPlayer;
    }
}

void Croupier::preparePostFlopPlayersToAct()
{
    spdlog::debug("Preparing post flop players to act...");
    auto isSbPlayer = [](const std::unique_ptr<Player>& player){ return player->getPosition() == Position::SB; };
    auto firstPlayer = std::find_if(players_.begin(), players_.end(), isSbPlayer);

    if (firstPlayer == players_.end()) //there is no SB player so we have less than 2 players, this is abnormal situation
    {
        spdlog::error("Cannot find SB player!");
        throw NoPlayerFoundError();
    }

    if ((*firstPlayer)->isActive())
    {
        spdlog::debug("First player to act is {} on position {}", (*firstPlayer)->getName(), (*firstPlayer)->getPosition());
        playersToAct_.push(firstPlayer->get());
        (*firstPlayer)->setBetSize(0);
    }

    auto nextPlayer = firstPlayer+1;

    while (nextPlayer != firstPlayer)
    {
        if (nextPlayer == players_.end())
        {
            nextPlayer = players_.begin();
            continue;
        }

        if ((*nextPlayer)->isActive())
        {
            spdlog::debug("Next player to act is {} on position {}", (*nextPlayer)->getName(), (*nextPlayer)->getPosition());
            playersToAct_.push(nextPlayer->get());
            (*nextPlayer)->setBetSize(0);
        }
        ++nextPlayer;
    }

    if (playersToAct_.size() == 1) //we have allin and still active player, but hand is over
        playersToAct_.pop();
}
