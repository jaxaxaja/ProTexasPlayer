#ifndef REAL_GAME_FACTORY_H
#define REAL_GAME_FACTORY_H

#include <memory>
#include <game/GameFactory.h>
#include <strategy/AhkStrategy.h>
#include <strategy/RealStrategy.h>
#include <deck/AhkDeck.h>

class RealGameFactory : public GameFactory
{
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy() override { return std::make_unique<RealStrategy>(); }
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy(const std::string &playerName = "") override { return std::make_unique<AhkStrategy>(); }
public:
    virtual std::unique_ptr<DeckImpl> createDeck() override { return std::make_unique<AhkDeck>(); }
    virtual std::vector<std::unique_ptr<Player>> createPlayers(Board& board) override;
    virtual ~RealGameFactory() = default;
};

#endif //REAL_GAME_FACTORY_H
