#ifndef GAME_SIMULATION_FACTORY_H
#define GAME_SIMULATION_FACTORY_H

#include <memory>
#include <game/GameFactory.h>
#include <strategy/AhkStrategy.h>
#include <strategy/RealStrategy.h>
#include <deck/AhkDeck.h>
#include <fstream>

class GameSimulationFactory : public GameFactory
{
    std::string strategy_;
    std::string file_;
    std::ifstream ins_;
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy(const Position) override { return {}; }
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy(const std::string &playerName = "",
                                                               const Position position = Position::EP) override;
public:
    virtual std::unique_ptr<DeckImpl> createDeck() override;
    virtual std::vector<std::unique_ptr<Player>> createPlayers(const Board &board, std::vector<PlayerMoveInfo>& playersMoveInfo) override;
    ~GameSimulationFactory() override = default;
};

#endif //GAME_SIMULATION_FACTORY_H
