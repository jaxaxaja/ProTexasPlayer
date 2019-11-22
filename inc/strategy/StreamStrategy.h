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
    std::unique_ptr<Move> checkOrBet(const Board& board = {}, const Hand& hand = {},
                                     const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    std::unique_ptr<Move> callRaiseOrFold(const float bb, const Board& board = {}, const Hand& hand = {},
                                          const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    ~StreamStrategy() override = default;
};

#endif //STREAM_STRATEGY_H
