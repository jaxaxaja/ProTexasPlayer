#ifndef AHK_STRATEGY_H
#define AHK_STRATEGY_H

#include <strategy/StrategyImpl.h>

class AhkStrategy : public StrategyImpl
{
public:
    std::unique_ptr<Move> checkOrBet(const Board& board = {}, const Hand& hand = {},
                                     const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    std::unique_ptr<Move> callRaiseOrFold(const float bb, const Board& board = {}, const Hand& hand = {},
                                          const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) override;
    virtual ~AhkStrategy() = default;
};

#endif //AHK_STRATEGY_H
