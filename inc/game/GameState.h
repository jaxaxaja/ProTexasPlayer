#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Croupier.h"

class Game;

class GameState
{
public:
    virtual void dealCards(Croupier& croupier) = 0;
    virtual void askPlayers(Croupier& croupier) = 0;
    virtual void nextState(Game* game) = 0;
    virtual ~GameState() = default;
};

#endif //GAME_STATE_H
