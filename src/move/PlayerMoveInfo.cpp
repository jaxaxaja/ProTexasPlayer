#include <move/PlayerMoveInfo.h>

std::ostream& operator<<(std::ostream& os, const MoveType& move)
{
    return os << (move == MoveType::Check ? "Check" : move == MoveType::Call ? "Call" : move == MoveType::Bet ? "Bet" : "Raise");
}
