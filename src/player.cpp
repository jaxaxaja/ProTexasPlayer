#include "player.h"

Player::Player(const std::string& name, const Board& board, Hand hand, size_t bigBlinds)
    : isActive_(true), name_(name), board_(board), hand_(hand), bigBlinds_(bigBlinds)
{
    //wczytac dane z bazy dotyczace statystyk
}

void Player::showHand()
{
    //zalogowac reke jaka mial gracz
}
