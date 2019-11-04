#ifndef TURN_H
#define TURN_H

#include <game/GameState.h>
#include <game/River.h>
#include <spdlog/spdlog.h>

class Turn : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
    }
    virtual void nextStreet(Game* game) override
    {
        spdlog::info("Finished Turn game state. Setting new state: River");
        game->setGameStreet(new River());
        delete this;
    }
    virtual ~Turn() = default;
};

#endif //TURN_H
