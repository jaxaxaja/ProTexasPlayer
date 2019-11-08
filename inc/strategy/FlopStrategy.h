#ifndef FLOP_STRATEGY_H
#define FLOP_STRATEGY_H

#include <strategy/StrategyState.h>

class FlopStrategy : public StrategyState
{
public:
    std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board, const Hand& hand) override;
    std::unique_ptr<Move> checkOrBet(const Board& board, const Hand& hand) override;
    virtual ~FlopStrategy() = default;
};

#endif //FLOP_STRATEGY_H
