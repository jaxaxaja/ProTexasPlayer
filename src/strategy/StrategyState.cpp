#include <strategy/StrategyState.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

StrategyState::StrategyState(const float bb, const Board& board, const Hand& hand,
                             const std::vector<PlayerMoveInfo>& playersMoveInfo)
    : bb_(bb), board_(board), hand_(hand), playersMoveInfo_(playersMoveInfo)
{}

std::unique_ptr<Move> StrategyState::play()
{
    spdlog::info("Calculating vsMove play...");

    const auto it = std::max_element(playersMoveInfo_.begin(), playersMoveInfo_.end(),
                                     [](const PlayerMoveInfo& lhs, const PlayerMoveInfo& rhs){ return lhs.moveType_ > rhs.moveType_; });
    MoveType highestMove = it != playersMoveInfo_.end() ? (*it).moveType_ : MoveType::Check;
    size_t highestMoveNumber = std::count_if(playersMoveInfo_.begin(), playersMoveInfo_.end(),
                                             [&highestMove](const PlayerMoveInfo& move){ return move.moveType_ == highestMove; });

    std::unique_ptr<Move> move;
    if (playersMoveInfo_.empty() || highestMove <= MoveType::Call)
        move = firstToAct();
    else if (highestMove == MoveType::Bet)
        move = vsBet(it);
    else if (highestMove == MoveType::Raise && highestMoveNumber == 1)
        move = vsRaise(it);
    else if (highestMove == MoveType::Raise && highestMoveNumber == 2)
        move = vs3Bet(it);
    else if (highestMove == MoveType::Raise && highestMoveNumber == 3)
        move = vs4Bet(it);
    else if (highestMove == MoveType::Raise && highestMoveNumber > 3)
        move = vsXBet(it);
    else
    {
        spdlog::error("Could not find proper vsMove play!");
        throw NoCounterPlayFoundError();
    }

    //call AHK scripts to make a move
    return move;
}
