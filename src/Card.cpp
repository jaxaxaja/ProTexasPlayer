#include "Card.h"

#include <type_traits>
#include <vector>

Card operator++(Card& x)
{
    return x = static_cast<Card>(std::underlying_type<Card>::type(x) + 1);
}

Card operator--(Card& x)
{
    return x = static_cast<Card>(std::underlying_type<Card>::type(x) - 1);
}

Card operator+(const Card& x, int y)
{
    return static_cast<Card>(std::underlying_type<Card>::type(x) + y);
}

Card operator-(const Card& x, int y)
{
    return static_cast<Card>(std::underlying_type<Card>::type(x) - y);
}

size_t operator%(const Card& x, int y)
{
    return static_cast<size_t>(x) % y;
}

size_t operator/(const Card& x, int y)
{
    return static_cast<size_t>(x) / y;
}


std::ostream& operator<<(std::ostream& os, const Card& c)
{
    static const std::vector<std::string> cardToString = {"As", "Ah", "Ad", "Ac",
                                                          "Ks", "Kh", "Kd", "Kc",
                                                          "Qs", "Qh", "Qd", "Qc",
                                                          "Js", "Jh", "Jd", "Jc",
                                                          "Ts", "Th", "Td", "Tc",
                                                          "9s", "9h", "9d", "9c",
                                                          "8s", "8h", "8d", "8c",
                                                          "7s", "7h", "7d", "7c",
                                                          "6s", "6h", "6d", "6c",
                                                          "5s", "5h", "5d", "5c",
                                                          "4s", "4h", "4d", "4c",
                                                          "3s", "3h", "3d", "3c",
                                                          "2s", "2h", "2d", "2c", "Unknown"};
    return os << cardToString.at(static_cast<size_t>(c));
}
