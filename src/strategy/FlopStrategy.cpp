#include<strategy/FlopStrategy.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"

FlopStrategy::FlopStrategy(const float bb, const Board& board, const Hand& hand,
                           const std::vector<PlayerMoveInfo>& playersMoveInfo)
    : StrategyState(bb, board, hand, playersMoveInfo)
{}

std::unique_ptr<Move> FlopStrategy::firstToAct()
{
    //evaluate hand
    //how to evaluate position and number of players in a hand?
    //cbet or donk or check
    //if aggressor
        //cont bet 60% best range
    //
}

std::unique_ptr<Move> FlopStrategy::vsDonk(std::vector<PlayerMoveInfo>::const_iterator it)
{
    //evaluate hand
    //evaluate draws
    //if ir->size_ <= 0.5 board.pot_
        //call
}

std::unique_ptr<Move> FlopStrategy::vsBet(std::vector<PlayerMoveInfo>::const_iterator it)
{
    //if aggressor
        //vsDonk
}

std::unique_ptr<Move> FlopStrategy::vsRaise(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> FlopStrategy::vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> FlopStrategy::vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> FlopStrategy::vsXBet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}
