#ifndef FLOP_H
#define FLOP_H

#include <game/GameState.h>

class Flop : public GameState
{
public:
    virtual void dealCards(const Croupier &croupier) override
    {
        croupier.dealFlopCards();
    }
    virtual void askPlayers(const Croupier& croupier) override;
};

#endif //FLOP_H
