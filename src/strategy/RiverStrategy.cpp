#include<strategy/RiverStrategy.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

RiverStrategy::RiverStrategy(const float bb, const Board& board, const Hand& hand,
                             const std::vector<PlayerMoveInfo>& playersMoveInfo)
    : StrategyState(bb, board,hand, playersMoveInfo)
{}

std::unique_ptr<Move> RiverStrategy::firstToAct()
{
    //postflop: first to act check or bet
    //if with AHK play call necessary scripts
}

std::unique_ptr<Move> RiverStrategy::vsDonk(std::vector<PlayerMoveInfo>::const_iterator it)
{
    //postflop: donk and hero aggr, raise or call or fold
    //if with AHK play call necessary scripts
}

std::unique_ptr<Move> RiverStrategy::vsBet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> RiverStrategy::vsRaise(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> RiverStrategy::vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> RiverStrategy::vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> RiverStrategy::vsXBet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

