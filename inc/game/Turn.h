#ifndef TURN_H
#define TURN_H

#include <game/GameState.h>

class Turn : public GameState
{
public:
    virtual void dealCards(const Croupier &croupier) override
    {
        croupier.dealTurnCards();
    }
    virtual void askPlayers(const Croupier& croupier) override;
};

#endif //TURN_H
