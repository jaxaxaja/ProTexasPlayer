#ifndef TURN_STRATEGY_H
#define TURN_STRATEGY_H

#include <strategy/StrategyState.h>

class TurnStrategy : public StrategyState
{
public:
    std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board, const Hand& hand) override;
    std::unique_ptr<Move> checkOrBet(const Board& board, const Hand& hand) override;
    virtual ~TurnStrategy() = default;
};

#endif //TURN_STRATEGY_H
