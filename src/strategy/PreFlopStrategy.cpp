#include <strategy/PreFlopStrategy.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <move/Call.h>
#include <move/Raise.h>
#include <move/Fold.h>
#include "Exceptions.h"

PreFlopStrategy::PreFlopStrategy(const Position& position, const float bb, const Board& board,
                                 const Hand& hand, const std::vector<PlayerMoveInfo>& playersMoveInfo)
    : StrategyState(bb, board, hand, playersMoveInfo), range_(position)
{}

std::unique_ptr<Move> PreFlopStrategy::firstToAct()
{
    spdlog::info("PreFlopStrategy: Playing according to firstToAct");

    if (range_.isInRfi(hand_))
    {
        int limpers = std::count_if(playersMoveInfo_.begin(), playersMoveInfo_.end(),
                         [](const PlayerMoveInfo& move){ return move.moveType_ == MoveType::Call; });
        return std::make_unique<Raise>(range_.getRfiSize() + 0.8*limpers);
    }
    else
        return std::make_unique<Fold>();
}

std::unique_ptr<Move> PreFlopStrategy::vsDonk(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::error("PreFlopStrategy: Playing vsDonk strategy on PreFlop!");
    throw WrongCounterPlayFoundError();
}

std::unique_ptr<Move> PreFlopStrategy::vsBet(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::error("PreFlopStrategy: Playing vsBet strategy on PreFlop!");
    throw WrongCounterPlayFoundError();
}

std::unique_ptr<Move> PreFlopStrategy::vsRaise(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::info("PreFlopStrategy: Playing according to vsRaise move");

    if (it->size_ > 5) //need to make it relative to stacksizes
        vs3Bet(it);

    if (range_.isInColdCall(hand_, it->position_))
        return std::make_unique<Call>();
    else if (range_.isIn3Bet(hand_, it->position_))
    {
        int coldCallers = std::count_if(it, playersMoveInfo_.end(),
                          [](const PlayerMoveInfo& move){ return move.moveType_ == MoveType::Call; });
        return std::make_unique<Raise>(range_.get3BetSize()*(it->size_) + 0.7*coldCallers*(it->size_));
    }
    else
        return std::make_unique<Fold>();
}

std::unique_ptr<Move> PreFlopStrategy::vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::info("PreFlopStrategy: Playing according to vs3Bet move");

    if (it->size_ > 15) //need to make it relative to stacksizes
        vs4Bet(it);

    int threeBetCallers = std::count_if(it, playersMoveInfo_.end(),
                          [](const PlayerMoveInfo& move){ return move.moveType_ == MoveType::Call; });

    if (threeBetCallers > 0 && range_.isInVsSqzCall(hand_, (*it).position_))
        return std::make_unique<Call>();
    else if (range_.isInVs3betCall(hand_, (*it).position_))
        return std::make_unique<Call>();
    else if (range_.isIn4Bet(hand_, (*it).position_))
        return std::make_unique<Raise>(range_.get4BetSize()*(it->size_) + 0.4*threeBetCallers*(it->size_));
    else
        return std::make_unique<Fold>();
}

std::unique_ptr<Move> PreFlopStrategy::vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::info("PreFlopStrategy: Playing according to vs4Bet move");

    if (it->size_ > 25) //need to make it relative to stacksizes
        vsXBet(it);

    if (range_.isInVs4betCall(hand_, (*it).position_))
        return std::make_unique<Call>();
    else if (range_.isInBroke(hand_, (*it).position_))
        return std::make_unique<Raise>(1000);
    else
        return std::make_unique<Fold>();
}

std::unique_ptr<Move> PreFlopStrategy::vsXBet(std::vector<PlayerMoveInfo>::const_iterator it)
{
    spdlog::info("PreFlopStrategy: Playing according to vsXBet move");

    if (range_.isInBroke(hand_, (*it).position_))
        return std::make_unique<Raise>(1000);
    else
        return std::make_unique<Fold>();
}
