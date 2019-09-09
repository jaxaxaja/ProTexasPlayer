#include "Croupier.h"

Croupier::Croupier(Board& board, std::vector<Player> &players)
    : board_(board), players_(players) {}

void Croupier::dealCardsToPlayers()
{
    for (auto& player : players_)
    {
        deck_->dealCardsToPlayer(player);
    }
}

void Croupier::dealFlopCards()
{
    deck_->dealFlopCards(board_);
}

void Croupier::dealTurnCards()
{
    deck_->dealTurnCards(board_);
}

void Croupier::dealRiverCards()
{
    deck_->dealRiverCards(board_);
}
