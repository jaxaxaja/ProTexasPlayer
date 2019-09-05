#ifndef AHK_DECK_H
#define AHK_DECK_H

#include <deck/DeckImpl.h>

class AhkDeck : public DeckImpl
{
public:
    virtual void dealCardsToPlayer(Player& player) override;
    virtual void dealFlopCards(Board& board) override;
    virtual void dealTurnCards(Board& board) override;
    virtual void dealRiverCards(Board& board) override;
};

#endif //AHK_DECK_H
