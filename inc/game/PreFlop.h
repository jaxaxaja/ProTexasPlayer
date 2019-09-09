#ifndef PRE_FLOP_H
#define PRE_FLOP_H

#include <game/GameState.h>

class PreFlop : public GameState
{
public:
    virtual void dealCards(const Croupier& croupier) override
    {
        croupier.dealCardsToPlayers();
    }
    virtual void askPlayers(const Croupier& croupier) override;
};

#endif //PRE_FLOP_H
