#include <strategy/StreamStrategy.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"

Move StreamStrategy::callRaiseOrFold(unsigned int bb)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify move (call, raise or fold): ";

    Move m;
    if (!parser_.parsePlayerMove(&ins_, m))
    {
        spdlog::error("Cannot parse player move from stream!");
        throw PlayerMoveParsingError();
    }

    if (m.first != Action::Call || m.first != Action::Raise || m.first != Action::Fold)
    {
        spdlog::error("Cannot use {} move from stream! Expected call, raise or fold!", m);
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

    if (m.first != Action::Check || m.first != Action::Bet || m.first != Action::Fold)
    {
        spdlog::error("Cannot use {} move from stream! Expected check or bet!", m);
        throw WrongPlayerMoveError();
    }

    return m;
}
