#ifndef REAL_STRATEGY_H
#define REAL_STRATEGY_H

#include <strategy/StrategyImpl.h>

class RealStrategy : public StrategyImpl
{
public:
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(unsigned int bb) override;
    virtual ~RealStrategy() = default;
};

#endif //REAL_STRATEGY_H
