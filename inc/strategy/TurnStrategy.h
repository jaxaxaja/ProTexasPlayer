#ifndef TURN_STRATEGY_H
#define TURN_STRATEGY_H

#include <strategy/StrategyState.h>

class TurnStrategy : public StrategyState
{
protected:
    std::unique_ptr<Move> firstToAct() override;
    std::unique_ptr<Move> vsDonk(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsBet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsRaise(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsXBet(std::vector<PlayerMoveInfo>::const_iterator it) override;
public:
    TurnStrategy(const float bb, const Board& board, const Hand& hand,
                 const std::vector<PlayerMoveInfo>& playersMoveInfo);
    ~TurnStrategy() = default;
};

#endif //TURN_STRATEGY_H
