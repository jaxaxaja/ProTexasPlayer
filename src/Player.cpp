#include "Player.h"

Player::Player(const std::string& name, const Board& board, size_t bigBlinds, Position position)
    : name_(name), board_(board), position_(position), bigBlinds_(bigBlinds)
{
    //wczytac dane z bazy dotyczace statystyk
}

Move Player::makeMove(const size_t bb)
{
    return Move(Action::Fold, 0);
}
