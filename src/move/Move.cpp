#include <move/Move.h>
#include <move/Fold.h>
#include <move/Bet.h>
#include <move/Call.h>
#include <move/Check.h>
#include <move/Raise.h>
#include <vector>
#include "Exceptions.h"

std::unique_ptr<Move> Move::createMove(const std::string& move, float size)
{
    if (move == "F")
        return std::make_unique<Fold>();
    else if (move == "CH")
        return std::make_unique<Check>();
    else if (move == "CA")
        return std::make_unique<Call>();
    else if (move == "B")
        return std::make_unique<Bet>(size);
    else if (move == "R")
        return std::make_unique<Raise>(size);
    else
        throw PlayerMoveParsingError();
}

std::ostream& operator<<(std::ostream& os, const Move& p)
{
    std::string move;
    move = p.isBet() ? "Bet" : p.isCall() ? "Call" : p.isCheck() ? "Check" : p.isFold() ? "Fold" : "Raise";
    os << move << (p.isBet() || p.isRaise() ? ": " + std::to_string(p.moveSize()) : "") ;
    return os;
}
