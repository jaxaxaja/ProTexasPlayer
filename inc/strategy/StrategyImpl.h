#ifndef STRATEGY_IMPL_H
#define STRATEGY_IMPL_H

#include <move/Move.h>
#include <iostream>

class StrategyImpl
{
public:
    static std::unique_ptr<StrategyImpl> createStrategy(const std::string& strategy, std::istream &ins = std::cin); //factory method
    virtual std::unique_ptr<Move> checkOrBet() = 0;
    virtual std::unique_ptr<Move> callRaiseOrFold(float bb) = 0;
    virtual ~StrategyImpl() = default;
};

#endif //STRATEGY_IMPL_H
