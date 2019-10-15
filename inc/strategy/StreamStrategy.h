#ifndef STREAM_STRATEGY_H
#define STREAM_STRATEGY_H

#include <strategy/StrategyImpl.h>
#include "StreamParser.h"
#include <iostream>

class StreamStrategy : public StrategyImpl
{
    std::istream& ins_;
    StreamParser parser_;

public:
    StreamStrategy(std::istream& ins) : ins_(ins) {}
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(const float bb) override;
    virtual ~StreamStrategy() = default;
};

#endif //STREAM_STRATEGY_H
