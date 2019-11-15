#include<strategy/TurnStrategy.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

TurnStrategy::TurnStrategy(const float bb, const Board& board, const Hand& hand,
                           const std::vector<PlayerMoveInfo>& playersMoveInfo)
    : StrategyState(bb, board, hand, playersMoveInfo)
{}

std::unique_ptr<Move> TurnStrategy::firstToAct()
{
    //postflop: first to act check or bet
    //if with AHK play call necessary scripts
}

std::unique_ptr<Move> TurnStrategy::vsDonk(std::vector<PlayerMoveInfo>::const_iterator it)
{
    //postflop: donk and hero aggr, raise or call or fold
    //if with AHK play call necessary scripts
}

std::unique_ptr<Move> TurnStrategy::vsBet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> TurnStrategy::vsRaise(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> TurnStrategy::vs3Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> TurnStrategy::vs4Bet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

std::unique_ptr<Move> TurnStrategy::vsXBet(std::vector<PlayerMoveInfo>::const_iterator it)
{

}

