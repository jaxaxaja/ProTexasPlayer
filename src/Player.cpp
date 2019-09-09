#include "Player.h"

Player::Player(const std::string& name, const Board& board, size_t bigBlinds)
    : isActive_(true), name_(name), board_(board), bigBlinds_(bigBlinds)
{
    //wczytac dane z bazy dotyczace statystyk
}

void Player::showHand() const
{
    //zalogowac reke jaka mial gracz
}
