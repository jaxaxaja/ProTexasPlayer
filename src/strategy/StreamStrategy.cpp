#include <strategy/StreamStrategy.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"

Move StreamStrategy::callRaiseOrFold(float bb)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify move (call, raise or fold): ";

    Move m;
    if (!parser_.parsePlayerMove(&ins_, m))
    {
        spdlog::error("Cannot parse player move from stream!");
        throw PlayerMoveParsingError();
    }

    if (m.first == Action::Bet)
    {
        spdlog::error("Cannot use {} move from stream! Expected call, raise, fold or check for BB!", m);
        throw WrongPlayerMoveError();
    }

    return m;
}

Move StreamStrategy::checkOrBet()
{
    if (&ins_ == &std::cin)
        std::cout << "Specify move (check or bet): ";

    Move m;
    if (!parser_.parsePlayerMove(&ins_, m))
    {
        spdlog::error("Cannot parse player move from steam!");
        throw PlayerMoveParsingError();
    }

    if (m.first == Action::Raise || m.first == Action::Call)
    {
        spdlog::error("Cannot use {} move from stream! Expected check, bet or fold!", m);
        throw WrongPlayerMoveError();
    }

    return m;
}
