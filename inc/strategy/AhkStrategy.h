#ifndef AHK_STRATEGY_H
#define AHK_STRATEGY_H

#include <strategy/StrategyImpl.h>

class AhkStrategy : public StrategyImpl
{
public:
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(unsigned int bb) override;
    virtual ~AhkStrategy() = default;
};

#endif //AHK_STRATEGY_H
