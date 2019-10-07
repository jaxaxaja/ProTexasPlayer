#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Croupier.h"
#include "Board.h"
#include <game/GameState.h>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

class Game
{
    long handNumber_;
    Board board_;
    std::string stake_;
    std::vector<Player> players_;
    Croupier croupier_;
    GameState* gameState_;

    FRIEND_TEST(GameTest, activePlayers);

public:
    Game(long handNumber, const std::string stake, const std::vector<Player>& players);
    ~Game();
    void playHand();
    void setGameState(GameState* state);
};

#endif //GAME_H
