#ifndef FLOP_H
#define FLOP_H

#include <game/GameState.h>
#include <game/Turn.h>
#include <spdlog/spdlog.h>

class Flop : public GameState
{
public:
    void dealCards(Croupier &croupier) override
    {
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
    }
    void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers();
    }
    void nextStreet(Game* game) override
    {
        spdlog::info("Finished Flop game state. Setting new state: Turn");
        game->setGameStreet(new Turn());
        delete this;
    }
    virtual ~Flop() = default;
};

#endif //FLOP_H
