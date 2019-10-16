#ifndef AHK_STRATEGY_H
#define AHK_STRATEGY_H

#include <strategy/StrategyImpl.h>

class AhkStrategy : public StrategyImpl
{
public:
    virtual std::unique_ptr<Move> checkOrBet() override;
    virtual std::unique_ptr<Move> callRaiseOrFold(const float bb) override;
    virtual ~AhkStrategy() = default;
};

#endif //AHK_STRATEGY_H
