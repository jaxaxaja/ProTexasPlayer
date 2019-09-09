#ifndef FLOP_H
#define FLOP_H

#include <game/GameState.h>
#include <game/Turn.h>

class Flop : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealFlopCards();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.checkOrBet();
    }
    virtual void nextState(Game* game) override
    {
        game->setGameState(new Turn());
        delete this;
    }
    virtual ~Flop() = default;
};

#endif //FLOP_H
