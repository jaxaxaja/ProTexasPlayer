#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Croupier.h"
#include "Board.h"
#include <game/GameState.h>
#include <vector>
#include <memory>

class Game
{
public:
    Game(long handNumber, const std::string stake, size_t numOfPlayers);
private:
    long handNumber_;
    Board board_;
    std::string stake_;
    std::vector<Player> players_;
    Croupier croupier_;
    std::unique_ptr<GameState> gameState_;
};

#endif //GAME_H
