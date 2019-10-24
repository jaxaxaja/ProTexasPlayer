#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <memory>
#include <strategy/StrategyImpl.h>
#include <deck/DeckImpl.h>

class GameFactory
{
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy() = 0;
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy() = 0;
public:
    virtual std::unique_ptr<DeckImpl> createDeck() = 0;
    virtual std::vector<std::unique_ptr<Player>> createPlayers(Board& board) = 0;
    virtual ~GameFactory() = default;
};

#endif //GAME_FACTORY_H
