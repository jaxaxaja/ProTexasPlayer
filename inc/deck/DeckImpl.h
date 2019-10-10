#ifndef DECK_IMPL_H
#define DECK_IMPL_H

#include "Board.h"
#include "Player.h"

class DeckImpl
{
public:
    virtual void dealCardsToPlayer(Player* player) = 0;
    virtual void dealFlopCards(Board& board) = 0;
    virtual void dealTurnCards(Board& board) = 0;
    virtual void dealRiverCards(Board& board) = 0;
    virtual ~DeckImpl() = default;
};

#endif //DECK_IMPL_H
