#include <strategy/RealStrategy.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

Move RealStrategy::callRaiseOrFold(const float bb)
{
    Move m;

    if (m.first == Action::Bet)
    {
        spdlog::error("Cannot use {} move generated by strategy, expected call, raise, fold or check for BB!", m);
        throw WrongPlayerMoveError();
    }

    return m;
}

Move RealStrategy::checkOrBet()
{
    Move m;

    if (m.first == Action::Raise || m.first == Action::Call)
    {
        spdlog::error("Cannot use {} move generated by strategy, expected check, bet or fold!", m);
        throw WrongPlayerMoveError();
    }

    return m;
}
