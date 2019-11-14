#ifndef REAL_GAME_FACTORY_H
#define REAL_GAME_FACTORY_H

#include <memory>
#include <game/GameFactory.h>
#include <strategy/AhkStrategy.h>
#include <strategy/RealStrategy.h>
#include <deck/AhkDeck.h>

class RealGameFactory : public GameFactory
{
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy(const Position position) override
    { return std::make_unique<RealStrategy>(position); }
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy(const std::string &playerName = "",
                                                               const Position position = Position::EP) override
    { return std::make_unique<AhkStrategy>(); }
public:
    virtual std::unique_ptr<DeckImpl> createDeck() override { return std::make_unique<AhkDeck>(); }
    virtual std::vector<std::unique_ptr<Player>> createPlayers(const Board &board, std::vector<PlayerMoveInfo> &playersMoveInfo) override;
    virtual ~RealGameFactory() = default;
};

#endif //REAL_GAME_FACTORY_H
