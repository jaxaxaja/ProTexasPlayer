#ifndef STRATEGY_STATE_H
#define STRATEGY_STATE_H

#include <move/Move.h>
#include "Board.h"
#include "Hand.h"

class StrategyState
{
public:
    virtual std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board, const Hand& hand) = 0;
    virtual std::unique_ptr<Move> checkOrBet(const Board& board, const Hand& hand) = 0;
    virtual ~StrategyState() = default;
};

#endif //STRATEGY_STATE_H
