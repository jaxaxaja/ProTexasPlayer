#ifndef REAL_STRATEGY_H
#define REAL_STRATEGY_H

#include <strategy/StrategyImpl.h>
#include <strategy/range/PositionalRange.h>
#include "Position.h"

class RealStrategy : public StrategyImpl
{
    PositionalRange range_;
public:
    RealStrategy(const Position position) : range_(position) {}
    virtual std::unique_ptr<Move> checkOrBet() override;
    virtual std::unique_ptr<Move> callRaiseOrFold(const float bb) override;
    virtual ~RealStrategy() = default;
};

#endif //REAL_STRATEGY_H
