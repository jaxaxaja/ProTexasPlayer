#ifndef GAME_SIMULATION_FACTORY_H
#define GAME_SIMULATION_FACTORY_H

#include <memory>
#include <game/GameFactory.h>
#include <strategy/AhkStrategy.h>
#include <strategy/RealStrategy.h>
#include <deck/AhkDeck.h>

class GameSimulationFactory : public GameFactory
{
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy() override;
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy() override;
public:
    virtual std::unique_ptr<DeckImpl> createDeck() override;
    virtual std::vector<std::unique_ptr<Player>> createPlayers(Board& board) override;
    virtual ~GameSimulationFactory() = default;
};

#endif //GAME_SIMULATION_FACTORY_H
