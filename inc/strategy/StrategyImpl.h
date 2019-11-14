#ifndef STRATEGY_IMPL_H
#define STRATEGY_IMPL_H

#include <move/Move.h>
#include <move/PlayerMoveInfo.h>
#include "Position.h"
#include "Board.h"
#include "Hand.h"
#include <iostream>

class StrategyImpl
{
public:
    static std::unique_ptr<StrategyImpl> createStrategy(const std::string& strategy, const Position position,
                                                        std::istream &ins = std::cin); //factory method
    virtual std::unique_ptr<Move> checkOrBet(const Board& board = {}, const Hand& hand = {},
                                             const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) = 0;
    virtual std::unique_ptr<Move> callRaiseOrFold(float bb, const Board& board = {}, const Hand& hand = {},
                                                  const std::vector<PlayerMoveInfo>& playersMoveInfo = {}) = 0;
    virtual ~StrategyImpl() = default;
};

#endif //STRATEGY_IMPL_H
