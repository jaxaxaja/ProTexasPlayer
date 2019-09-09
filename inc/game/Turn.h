#ifndef TURN_H
#define TURN_H

#include <game/GameState.h>
#include <game/River.h>

class Turn : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealTurnCards();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.checkOrBet();
    }
    virtual void nextState(Game* game) override
    {
        game->setGameState(new River());
        delete this;
    }
    virtual ~Turn() = default;
};

#endif //TURN_H
