#ifndef MOVE_H
#define MOVE_H

#include <utility>

enum class Action
{
    Fold, Check, Call, Bet, Raise
};

using Move = std::pair<Action, unsigned int>;

#endif //MOVE_H
