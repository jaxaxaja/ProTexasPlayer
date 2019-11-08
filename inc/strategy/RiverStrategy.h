#ifndef RIVER_STRATEGY_H
#define RIVER_STRATEGY_H

#include <strategy/StrategyState.h>

class RiverStrategy : public StrategyState
{
public:
    std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board, const Hand& hand) override;
    std::unique_ptr<Move> checkOrBet(const Board& board, const Hand& hand) override;
    virtual ~RiverStrategy() = default;
};

#endif //RIVER_STRATEGY_H
