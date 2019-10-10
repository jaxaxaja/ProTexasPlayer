#ifndef POSITION_H
#define POSITION_H

#include <ostream>

enum class Position
{
    BU, SB, BB, EP, MP, CO, Unknown
};

std::ostream& operator<<(std::ostream& os, const Position& p);

#endif //POSITION_H
