#ifndef PLAYER_MOVE_INFO_H
#define PLAYER_MOVE_INFO_H

#include "Position.h"
#include <move/Move.h>

enum class MoveType {Check, Call, Bet, Raise};

std::ostream& operator<<(std::ostream& os, const MoveType& move);

struct PlayerMoveInfo
{
    PlayerMoveInfo(const std::unique_ptr<Move>& move, Position position, float size, float stackLeft) :
    position_(position), size_(size), stackLeft_(stackLeft)
    { moveType_ = move->isBet() ? MoveType::Bet : move->isCall() ? MoveType::Call : move->isCheck() ? MoveType::Check : MoveType::Raise; }

    MoveType moveType_;
    Position position_;
    float size_;
    float stackLeft_;
};

#endif //PLAYER_MOVE_INFO_H
