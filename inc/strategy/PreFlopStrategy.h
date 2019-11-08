#ifndef PRE_FLOP_STRATEGY_H
#define PRE_FLOP_STRATEGY_H

#include <strategy/StrategyState.h>
#include <strategy/range/PositionalRange.h>

class PreFlopStrategy : public StrategyState
{
    PositionalRange range_;
public:
    PreFlopStrategy(const Position& position) : range_(position) {}
    std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board, const Hand& hand) override;
    std::unique_ptr<Move> checkOrBet(const Board& board, const Hand& hand) override { return nullptr; }
    virtual ~PreFlopStrategy() = default;
};

#endif //PRE_FLOP_STRATEGY_H
