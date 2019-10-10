#ifndef STANDARD_INPUT_STRATEGY_H
#define STANDARD_INPUT_STRATEGY_H

#include <strategy/StrategyImpl.h>

class StandardInputStrategy : public StrategyImpl
{
public:
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(unsigned int bb) override;
    virtual ~StandardInputStrategy() = default;
};

#endif //STANDARD_INPUT_STRATEGY_H
