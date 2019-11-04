#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Croupier.h"
#include "Board.h"
#include <game/GameState.h>
#include <game/GameFactory.h>
#include <vector>
#include <gtest/gtest.h>

class Game
{
    Board board_;
    std::vector<std::unique_ptr<Player>> players_;
    Croupier croupier_;
    GameState* gameState_ = nullptr;
    size_t playersInHand();

public:
    Game(std::unique_ptr<DeckImpl>& deck, std::unique_ptr<GameFactory>& gameFactory);
    ~Game();
    void playHand();
    void setGameStreet(GameState* state);
};

#endif //GAME_H
