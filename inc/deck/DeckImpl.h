#ifndef DECK_IMPL_H
#define DECK_IMPL_H

#include "Board.h"
#include "Player.h"

class DeckImpl
{
public:
    static std::unique_ptr<DeckImpl> createDeck(const std::string& deck, std::istream &ins = std::cin); //factory method
    virtual void dealCardsToPlayer(std::unique_ptr<Player>& player) = 0;
    virtual void dealFlopCards(Board& board) = 0;
    virtual void dealTurnCards(Board& board) = 0;
    virtual void dealRiverCards(Board& board) = 0;
    virtual ~DeckImpl() = default;
};

#endif //DECK_IMPL_H
