#ifndef REAL_STRATEGY_H
#define REAL_STRATEGY_H

#include <strategy/StrategyImpl.h>
#include <strategy/PreFlopStrategy.h>
#include "Position.h"

class RealStrategy : public StrategyImpl
{
    std::unique_ptr<StrategyState> realStrategy_;
    void createRealStrategy(const Board& board);
public:
    RealStrategy(const Position position) : realStrategy_(std::make_unique<PreFlopStrategy>(position)) {}
    std::unique_ptr<Move> checkOrBet(const Board &board, const Hand& hand = {},
                                     const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    std::unique_ptr<Move> callRaiseOrFold(const float bb, const Board& board, const Hand& hand = {},
                                          const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    virtual ~RealStrategy() = default;
};

#endif //REAL_STRATEGY_H
