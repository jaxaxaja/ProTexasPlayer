#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <ostream>

enum class Action
{
    Fold, Check, Call, Bet, Raise, Unknown
};

using Move = std::pair<Action, unsigned int>;

std::ostream& operator<<(std::ostream& os, const Move& p);

#endif //MOVE_H
