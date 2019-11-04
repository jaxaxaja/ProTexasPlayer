#ifndef PRE_FLOP_H
#define PRE_FLOP_H

#include <game/GameState.h>
#include <game/Flop.h>
#include <spdlog/spdlog.h>

class PreFlop : public GameState
{
public:
    virtual void dealCards(Croupier& croupier) override
    {
        croupier.dealCardsToPlayers();
        croupier.preparePreFlopPlayersToAct();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.askPlayers(1);
    }
    virtual void nextStreet(Game* game) override
    {
        spdlog::info("Finished Pre Flop game state. Setting new state: Flop");
        game->setGameStreet(new Flop());
        delete this;
    }
    virtual ~PreFlop() = default;
};

#endif //PRE_FLOP_H
