#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "croupier.h"
#include "board.h"
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
    std::vector<std::unique_ptr<Player>> players_;
    Croupier croupier_;
};

#endif //GAME_H
