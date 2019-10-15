#include "Croupier.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"

Croupier::Croupier(Board& board, const std::vector<Player*> &players, std::unique_ptr<DeckImpl> deck)
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
    while (!playersToAct_.empty())
    {
        Player* playerToAct = playersToAct_.front();
        playersToAct_.pop();
        const Move playerMove = playerToAct->makeMove(bb);

        if (playerMove.first == Action::Raise || playerMove.first == Action::Bet)
        {
            for (auto& player : hypotheticalPlayers_ToAct_)
                playersToAct_.push(player);

            hypotheticalPlayers_ToAct_.clear();
            hypotheticalPlayers_ToAct_.push_back(playerToAct);
            bb = playerMove.second;
            board_.pot_ += bb;
        }

        if (playerMove.first != Action::Fold)
            hypotheticalPlayers_ToAct_.push_back(playerToAct);

        if (playerMove.first == Action::Call)
            board_.pot_ += playerMove.second;
    }

    hypotheticalPlayers_ToAct_.clear();

    if (activePlayers() <= 1) //end of a Hand, rest of Players have folded
    {
        auto isActive = [](const Player* player){ return player->isActive(); };
        auto winner = std::find_if(players_.begin(), players_.end(), isActive);

        if (winner == players_.end())
            throw NoActivePlayerFoundError();

        (*winner)->addMoney(board_.pot_);
    }
}

size_t Croupier::activePlayers()
{
    auto active = [](const Player* player) { return player->isActive(); };
    return std::count_if(players_.begin(), players_.end(), active);
}

void Croupier::initializeSbAndBb(Position sb, Position bb)
{
    auto isSbPlayer = [&sb](const Player* player){ return player->getPosition() == sb; };
    auto isBbPlayer = [&bb](const Player* player){ return player->getPosition() == bb; };

    auto sbPlayer = std::find_if(players_.begin(), players_.end(), isSbPlayer);
    auto bbPlayer = std::find_if(players_.begin(), players_.end(), isBbPlayer);

    if (sbPlayer == players_.end() || bbPlayer == players_.end())
    {
        spdlog::error("Cannot initialize SB and BB player!");
        throw NoPlayerFoundError();
    }

    (*sbPlayer)->setSbBetSize();
    (*bbPlayer)->setBbBetSize();
}

void Croupier::preparePreFlopPlayersToAct()
{
    auto isEpPlayer = [](const Player* player){ return player->getPosition() == Position::EP; };
    auto firstPlayer = std::find_if(players_.begin(), players_.end(), isEpPlayer);

    if (firstPlayer == players_.end()) //there is no EP player so we have less than 4 players
    {
        if (players_.size() == 3) //BU is first to act
        {
            auto isBuPlayer = [](const Player* player){ return player->getPosition() == Position::BU; };
            firstPlayer = std::find_if(players_.begin(), players_.end(), isBuPlayer);
            initializeSbAndBb(Position::SB, Position::BB);
        }
        else //SB is first to act
        {
            auto isSbPlayer = [](const Player* player){ return player->getPosition() == Position::SB; };
            firstPlayer = std::find_if(players_.begin(), players_.end(), isSbPlayer);
            initializeSbAndBb(Position::BU, Position::SB);
        }

        if (firstPlayer == players_.end()) //there is no SB nor BB player so we have less than 2 players, this is abnormal situation
        {
            spdlog::error("Cannot find Button nor SB player!");
            throw NoPlayerFoundError();
        }
    }

    playersToAct_.push(*firstPlayer);
    auto nextPlayer = firstPlayer+1;

    while (nextPlayer != firstPlayer)
    {
        if (nextPlayer == players_.end())
        {
            nextPlayer = players_.begin();
            continue;
        }
        playersToAct_.push(*nextPlayer);
        ++nextPlayer;
    }
}

void Croupier::preparePostFlopPlayersToAct()
{
    auto isSbPlayer = [](const Player* player){ return player->getPosition() == Position::SB; };
    auto firstPlayer = std::find_if(players_.begin(), players_.end(), isSbPlayer);

    if (firstPlayer == players_.end()) //there is no SB player so we have less than 2 players, this is abnormal situation
    {
        spdlog::error("Cannot find SB player!");
        throw NoPlayerFoundError();
    }

    if ((*firstPlayer)->isActive())
    {
        playersToAct_.push(*firstPlayer);
        (*firstPlayer)->resetBetSize();
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
            playersToAct_.push(*nextPlayer);
            (*nextPlayer)->resetBetSize();
        }
        ++nextPlayer;
    }
}
