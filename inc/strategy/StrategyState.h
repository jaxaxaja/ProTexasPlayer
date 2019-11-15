#ifndef STRATEGY_STATE_H
#define STRATEGY_STATE_H

#include <move/Move.h>
#include <move/PlayerMoveInfo.h>
#include "Board.h"
#include "Hand.h"

class StrategyState
{
protected:
    const float bb_;
    const Board& board_;
    const Hand& hand_;
    const std::vector<PlayerMoveInfo>& playersMoveInfo_;
    //bool isInPosition() = 0;
    //bool isAggressor() = 0;
    virtual std::unique_ptr<Move> firstToAct() = 0;
    virtual std::unique_ptr<Move> vsDonk(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
    virtual std::unique_ptr<Move> vsBet(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
    virtual std::unique_ptr<Move> vsRaise(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
    virtual std::unique_ptr<Move> vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
    virtual std::unique_ptr<Move> vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
    virtual std::unique_ptr<Move> vsXBet(std::vector<PlayerMoveInfo>::const_iterator it) = 0;
public:
    StrategyState(const float bb, const Board& board, const Hand& hand,
                  const std::vector<PlayerMoveInfo>& playersMoveInfo);
    std::unique_ptr<Move> play();
    virtual ~StrategyState() = default;
};

#endif //STRATEGY_STATE_H
