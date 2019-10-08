#ifndef FLOP_H
#define FLOP_H

#include <game/GameState.h>
#include <game/Turn.h>
#include <spdlog/spdlog.h>

class Flop : public GameState
{
public:
    virtual void dealCards(Croupier &croupier) override
    {
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
    }
    virtual void nextState(Game* game) override
    {
        spdlog::info("Finished Flop game state. Setting new state: Turn");
        game->setGameState(new Turn());
        delete this;
    }
    virtual ~Flop() = default;
};

#endif //FLOP_H
