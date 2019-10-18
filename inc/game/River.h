#ifndef RIVER_H
#define RIVER_H

#include <game/GameState.h>
#include <spdlog/spdlog.h>

class River : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealRiverCards();
        croupier.preparePostFlopPlayersToAct();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
        croupier.chooseWinner();
    }
    virtual void nextState(Game* game) override
    {
        spdlog::info("Finished River game state.");
        game->setGameState(nullptr);
        delete this;
    }
    virtual ~River() = default;
};

#endif //RIVER_H
