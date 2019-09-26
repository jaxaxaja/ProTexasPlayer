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

#endif //EXCEPTIONS_H
