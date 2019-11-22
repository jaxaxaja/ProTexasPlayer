#ifndef REAL_STRATEGY_H
#define REAL_STRATEGY_H

#include <strategy/StrategyImpl.h>
#include <strategy/PreFlopStrategy.h>
#include "Position.h"
#include <gtest/gtest.h>

class RealStrategy : public StrategyImpl
{
    std::unique_ptr<StrategyState> realStrategy_;
    Position position_;
    void createRealStrategy(const float bb, const Board& board, const Hand& hand,
                            const std::vector<PlayerMoveInfo>& playersMoveInfo);
    FRIEND_TEST(RealStrategyTest, CreateRealStrategy);

public:
    RealStrategy(const Position position) : position_(position) {}
    std::unique_ptr<Move> checkOrBet(const Board &board, const Hand& hand = {},
                                     const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    std::unique_ptr<Move> callRaiseOrFold(const float bb, const Board& board, const Hand& hand = {},
                                          const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    ~RealStrategy() override = default;
};

#endif //REAL_STRATEGY_H
