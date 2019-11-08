#include <strategy/StrategyImpl.h>
#include <strategy/RealStrategy.h>
#include <strategy/StreamStrategy.h>
#include "Exceptions.h"

std::unique_ptr<StrategyImpl> StrategyImpl::createStrategy(const std::string& strategy, const Position position, std::istream &ins)
{
    if (strategy == "R")
        return std::make_unique<RealStrategy>(position);
    else if (strategy == "F" || strategy == "S")
        return std::make_unique<StreamStrategy>(ins);
    else
        throw WrongUserInputError();
}
