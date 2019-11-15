#ifndef FLOP_STRATEGY_H
#define FLOP_STRATEGY_H

#include <strategy/StrategyState.h>

class FlopStrategy : public StrategyState
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
    FlopStrategy(const float bb, const Board& board, const Hand& hand,
                 const std::vector<PlayerMoveInfo>& playersMoveInfo);
    virtual ~FlopStrategy() = default;
};

#endif //FLOP_STRATEGY_H
