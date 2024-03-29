#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <memory>
#include <strategy/StrategyImpl.h>
#include <deck/DeckImpl.h>

class GameFactory
{
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy(const Position position) = 0;
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy(const std::string &playerName = "",
                                                               const Position position = Position::EP) = 0;
public:
    virtual std::unique_ptr<DeckImpl> createDeck() = 0;
    virtual std::vector<std::unique_ptr<Player>> createPlayers(const Board& board, std::vector<PlayerMoveInfo>& playersMoveInfo) = 0;
    virtual ~GameFactory() = default;
};

#endif //GAME_FACTORY_H
