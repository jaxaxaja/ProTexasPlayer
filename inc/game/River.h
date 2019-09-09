#ifndef RIVER_H
#define RIVER_H

#include <game/GameState.h>

class River : public GameState
{
public:
    virtual void dealCards(const Croupier &croupier) override
    {
        croupier.dealRiverCards();
    }
    virtual void askPlayers(const Croupier& croupier) override;
};

#endif //RIVER_H
