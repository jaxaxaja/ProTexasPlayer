#ifndef PRE_FLOP_H
#define PRE_FLOP_H

#include <game/GameState.h>
#include <game/Flop.h>

class PreFlop : public GameState
{
public:
    virtual void dealCards(Croupier& croupier) override
    {
        croupier.dealCardsToPlayers();
    }
    virtual void askPlayers(Croupier& croupier) override
    {
        croupier.callRaiseOrFold();
    }
    virtual void nextState(Game* game) override
    {
        game->setGameState(new Flop());
        delete this;
    }
    virtual ~PreFlop() = default;
};

#endif //PRE_FLOP_H
