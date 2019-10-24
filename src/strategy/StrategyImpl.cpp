#include <strategy/StrategyImpl.h>
#include <strategy/RealStrategy.h>
#include <strategy/StreamStrategy.h>
#include "Exceptions.h"

std::unique_ptr<StrategyImpl> createStrategy(const std::string& strategy, std::istream &ins)
{
    if (strategy == "R")
        return std::make_unique<RealStrategy>();
    else if (strategy == "F" || strategy == "S")
        return std::make_unique<StreamStrategy>(ins);
    else
        throw WrongUserInputError();
}
