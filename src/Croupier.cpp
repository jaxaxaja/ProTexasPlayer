#include "Croupier.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

Croupier::Croupier(Board& board, std::vector<Player> &players)
    : board_(board), players_(players) {}

void Croupier::dealCardsToPlayers()
{
    for (auto& player : players_)
    {
        deck_->dealCardsToPlayer(player);
        spdlog::info("Dealt hand to player {}: {}", player.getName(), player.showHand());
    }
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

void Croupier::checkOrBet()
{

}

void Croupier::callRaiseOrFold()
{

}

size_t Croupier::activePlayers()
{
    auto Active = [](const Player& player) { return player.isActive(); };
    return std::count_if(players_.begin(), players_.end(), Active);
}
