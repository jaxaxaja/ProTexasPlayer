#include "Player.h"

Player::Player(const std::string& name, const Board& board, size_t bigBlinds)
    : isActive_(true), name_(name), board_(board), bigBlinds_(bigBlinds)
{
    //wczytac dane z bazy dotyczace statystyk
}

std::string Player::showHand() const
{
    return hand_.getHand();
}
