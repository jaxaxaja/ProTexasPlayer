#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Croupier.h"

class GameState
{
public:
    virtual void dealCards(const Croupier& croupier) = 0;
    virtual void askPlayers(const Croupier& croupier) = 0;
};

#endif //GAME_STATE_H
