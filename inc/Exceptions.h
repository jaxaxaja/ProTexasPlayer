#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

struct FlopParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing flop cards error";}
};

struct TurnParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing turn cards error";}
};

struct RiverParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing river cards error";}
};

struct PlayerHandParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing player hand error";}
};

struct PlayerMoveParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing player move error";}
};

struct NoPlayerFoundError : public std::exception
{
    virtual const char* what() const noexcept override {"Cannot find player when preparing list of players to act";}
};

struct NoActivePlayerFoundError : public std::exception
{
    virtual const char* what() const noexcept override {"Cannot find active player when looking for a winner";}
};

struct WrongPlayerMoveError : public std::exception
{
    virtual const char* what() const noexcept override {"Wrong player move error";}
};

struct WrongUserInputError : public std::exception
{
    virtual const char* what() const noexcept override {"Wrong user input error";}
};

struct RangeParsingError : public std::exception
{
    virtual const char* what() const noexcept override {"Parsing range error";}
};

#endif //EXCEPTIONS_H
