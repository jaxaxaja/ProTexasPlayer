#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

struct FlopParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing flop cards error"; }
};

struct TurnParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing turn cards error"; }
};

struct RiverParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing river cards error"; }
};

struct PlayerHandParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing player hand error"; }
};

struct PlayerMoveParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing player move error"; }
};

struct NoPlayerFoundError : public std::exception
{
    virtual const char* what() const noexcept override { return "Cannot find player when preparing list of players to act"; }
};

struct NoActivePlayerFoundError : public std::exception
{
    virtual const char* what() const noexcept override { return "Cannot find active player when looking for a winner"; }
};

struct WrongPlayerMoveError : public std::exception
{
    virtual const char* what() const noexcept override { return "Wrong player move error"; }
};

struct WrongUserInputError : public std::exception
{
    virtual const char* what() const noexcept override { return "Wrong user input error"; }
};

struct RangeParsingError : public std::exception
{
    virtual const char* what() const noexcept override { return "Parsing range error"; }
};

struct NoCounterPlayFoundError : public std::exception
{
    virtual const char* what() const noexcept override {return "Cound not find counter play vs other players error"; }
};

struct WrongCounterPlayFoundError : public std::exception
{
    virtual const char* what() const noexcept override { return "Found wrong counter play vs other players error"; }
};

struct NotEnoughCardsError : public std::exception
{
    virtual const char* what() const noexcept override { return "No flop, turn or river card available for hand evaluation"; }
};

#endif //EXCEPTIONS_H
