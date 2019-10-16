#ifndef STRATEGY_IMPL_H
#define STRATEGY_IMPL_H

#include <move/Move.h>

class StrategyImpl
{
public:
    virtual std::unique_ptr<Move> checkOrBet() = 0;
    virtual std::unique_ptr<Move> callRaiseOrFold(float bb) = 0;
    virtual ~StrategyImpl() = default;
};

#endif //STRATEGY_IMPL_H
