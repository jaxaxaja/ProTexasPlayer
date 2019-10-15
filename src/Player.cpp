#include "Player.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

Player::Player(const std::string& name, const Board& board, float bigBlinds, Position position, std::unique_ptr<StrategyImpl> strategy)
    : name_(name), board_(board), position_(position), bigBlinds_(bigBlinds), strategy_(std::move(strategy))
{
    //wczytac dane z bazy dotyczace statystyk
}

Move Player::makeMove(const float bb)
{
    Move m;

    if (bb > 0)
        m = strategy_->callRaiseOrFold(bb);
    else
        m = strategy_->checkOrBet();

    spdlog::info("Player {} on position {} makes a move {}", getName(), getPosition(), m);

    //moze lepiej Move'a zrobic jako klase z wirtualna metoda updatePlayer(Player* player)
    // i te wyliczenia ponizej bedzie robic w tej metodzie
    if (m.first == Action::Fold)
        isActive_ = false;
    else if (m.first == Action::Call) //calculate size of a call based on previous betSizes
    {
        m.second = bb - betSize_;
        bigBlinds_ -= m.second;
        betSize_ = bb;
    }
    else if (m.first != Action::Check)
    {
        bigBlinds_ -= m.second - betSize_;
        float tmp = betSize_;
        betSize_ = m.second;
        m.second -= tmp;
    }

    if (bigBlinds_ <= 0)
        isActive_ = false;

    return m;
}
