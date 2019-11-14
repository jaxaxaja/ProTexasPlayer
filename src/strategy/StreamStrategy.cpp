#include <strategy/StreamStrategy.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Exceptions.h"

std::unique_ptr<Move> StreamStrategy::callRaiseOrFold(float, const Board&, const Hand&, const std::vector<PlayerMoveInfo>&)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify move (call, raise or fold): ";

    std::unique_ptr<Move> move;
    if (!parser_.parsePlayerMove(&ins_, move))
    {
        spdlog::error("Cannot parse player move from stream!");
        throw PlayerMoveParsingError();
    }

    if (move->isBet())
    {
        spdlog::error("Cannot use {} move from stream! Expected call, raise, fold or check for BB!", *move);
        throw WrongPlayerMoveError();
    }

    return move;
}

std::unique_ptr<Move> StreamStrategy::checkOrBet(const Board&, const Hand&, const std::vector<PlayerMoveInfo>&)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify move (check or bet): ";

    std::unique_ptr<Move> move;
    if (!parser_.parsePlayerMove(&ins_, move))
    {
        spdlog::error("Cannot parse player move from steam!");
        throw PlayerMoveParsingError();
    }

    if (move->isRaise() || move->isCall())
    {
        spdlog::error("Cannot use {} move from stream! Expected check, bet or fold!", *move);
        throw WrongPlayerMoveError();
    }

    return move;
}
