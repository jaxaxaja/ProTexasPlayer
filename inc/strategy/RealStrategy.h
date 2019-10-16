#ifndef REAL_STRATEGY_H
#define REAL_STRATEGY_H

#include <strategy/StrategyImpl.h>

class RealStrategy : public StrategyImpl
{
public:
    virtual std::unique_ptr<Move> checkOrBet() override;
    virtual std::unique_ptr<Move> callRaiseOrFold(const float bb) override;
    virtual ~RealStrategy() = default;
};

#endif //REAL_STRATEGY_H
