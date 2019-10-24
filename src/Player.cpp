#include "Player.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

Player::Player(const std::string& name, const Board& board, float bigBlinds, Position position, std::unique_ptr<StrategyImpl> strategy)
    : name_(name), board_(board), position_(position), bigBlinds_(bigBlinds), strategy_(std::move(strategy))
{
    //wczytac dane z bazy dotyczace statystyk
}

std::unique_ptr<Move> Player::makeMove(const float bb)
{
    std::unique_ptr<Move> move;

    if (bb > 0)
        move = strategy_->callRaiseOrFold(bb);
    else
        move = strategy_->checkOrBet();

    spdlog::info("Player {} on position {} makes a move {}", getName(), getPosition(), *move);

    move->updatePlayer(this, bb);

    return move;
}
