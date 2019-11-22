#ifndef TURN_H
#define TURN_H

#include <game/GameState.h>
#include <game/River.h>
#include <spdlog/spdlog.h>

class Turn : public GameState
{
public:
    void dealCards(Croupier &croupier) override
    {
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
    }
    void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
    }
    void nextStreet(Game* game) override
    {
        spdlog::info("Finished Turn game state. Setting new state: River");
        game->setGameStreet(new River());
        delete this;
    }
    ~Turn() override = default;
};

#endif //TURN_H
