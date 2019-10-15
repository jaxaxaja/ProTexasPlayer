#ifndef STRATEGY_IMPL_H
#define STRATEGY_IMPL_H

#include "Move.h"

class StrategyImpl
{
public:
    virtual Move checkOrBet() = 0;
    virtual Move callRaiseOrFold(float bb) = 0;
    virtual ~StrategyImpl() = default;
};

#endif //STRATEGY_IMPL_H
