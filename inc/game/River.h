#ifndef RIVER_H
#define RIVER_H

#include <game/GameState.h>

class River : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealRiverCards();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.checkOrBet();
    }
    virtual void nextState(Game* game) override
    {
        game->setGameState(nullptr);
        delete this;
    }
    virtual ~River() = default;
};

#endif //RIVER_H
