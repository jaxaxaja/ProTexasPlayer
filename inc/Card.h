#ifndef CARD_H
#define CARD_H

#include <ostream>

enum class Card
{
    As, Ah, Ad, Ac,
    Ks, Kh, Kd, Kc,
    Qs, Qh, Qd, Qc,
    Js, Jh, Jd, Jc,
    Ts, Th, Td, Tc,
    NineS, NineH, NineD, NineC,
    EightS, EightH, EightD, EightC,
    SevenS, SevenH, SevenD, SevenC,
    SixS, SixH, SixD, SixC,
    FiveS, FiveH, FiveD, FiveC,
    FourS, FourH, FourD, FourC,
    ThreeS, ThreeH, ThreeD, ThreeC,
    TwoS, TwoH, TwoD, TwoC, Unknown
};

Card operator++(Card& x);
std::ostream& operator<<(std::ostream& os, const Card& c);

#endif // CARD_H
