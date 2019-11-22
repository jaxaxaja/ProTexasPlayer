#ifndef RIVER_H
#define RIVER_H

#include <game/GameState.h>
#include <spdlog/spdlog.h>

class River : public GameState
{
public:
    void dealCards(Croupier &croupier) override
    {
        croupier.dealRiverCards();
        croupier.preparePostFlopPlayersToAct();
    }
    void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
    }
    void nextStreet(Game* game) override
    {
        spdlog::info("Finished River game state.");
        game->setGameStreet(nullptr);
        delete this;
    }
    ~River() override = default;
};

#endif //RIVER_H
