#ifndef PRE_FLOP_STRATEGY_H
#define PRE_FLOP_STRATEGY_H

#include <strategy/StrategyState.h>
#include <strategy/range/PositionalRange.h>

class PreFlopStrategy : public StrategyState
{
    PositionalRange range_;
protected:
    std::unique_ptr<Move> firstToAct() override;
    std::unique_ptr<Move> vsDonk(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsBet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsRaise(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it) override;
    std::unique_ptr<Move> vsXBet(std::vector<PlayerMoveInfo>::const_iterator it) override;
public:
    PreFlopStrategy(const Position& position, const float bb, const Board& board,
                    const Hand& hand, const std::vector<PlayerMoveInfo>& playersMoveInfo);
    virtual ~PreFlopStrategy() = default;
};

#endif //PRE_FLOP_STRATEGY_H
