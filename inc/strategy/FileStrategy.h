#ifndef FILE_STRATEGY_H
#define FILE_STRATEGY_H

#include <strategy/StrategyImpl.h>

class FileStrategy : public StrategyImpl
{
public:
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(unsigned int bb) override;
};

#endif //FILE_STRATEGY_H
