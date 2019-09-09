#include "Hand.h"

const std::map<Card, std::string> Hand::cardToStringMap_ = {{Card::As, "As"}, {Card::Ah, "Ah"}, {Card::Ad, "Ad"}, {Card::Ac, "Ac"},
                                                            {Card::Ks, "Ks"}, {Card::Kh, "Kh"}, {Card::Kd, "Kd"}, {Card::Kc, "Kc"},
                                                            {Card::Qs, "Qs"}, {Card::Qh, "Qh"}, {Card::Qd, "Qd"}, {Card::Qc, "Qc"},
                                                            {Card::Js, "Js"}, {Card::Jh, "Jh"}, {Card::Jd, "Jd"}, {Card::Jc, "Jc"},
                                                            {Card::Ts, "Ts"}, {Card::Th, "Th"}, {Card::Td, "Td"}, {Card::Tc, "Tc"},
                                                            {Card::NineS, "9s"}, {Card::NineH, "9h"}, {Card::NineD, "9d"}, {Card::NineC, "9c"},
                                                            {Card::EightS, "8s"}, {Card::EightH, "8h"}, {Card::EightD, "8d"}, {Card::EightC, "8c"},
                                                            {Card::SevenS, "7s"}, {Card::SevenH, "7h"}, {Card::SevenD, "7d"}, {Card::SevenC, "7c"},
                                                            {Card::SixS, "6s"}, {Card::SixH, "6h"}, {Card::SixD, "6d"}, {Card::SixC, "6c"},
                                                            {Card::FiveS, "5s"}, {Card::FiveH, "5h"}, {Card::FiveD, "5d"}, {Card::FiveC, "5c"},
                                                            {Card::FourS, "4s"}, {Card::FourH, "4h"}, {Card::FourD, "4d"}, {Card::FourC, "4c"},
                                                            {Card::ThreeS, "3s"}, {Card::ThreeH, "3h"}, {Card::ThreeD, "3d"}, {Card::ThreeC, "3c"},
                                                            {Card::TwoS, "2s"}, {Card::TwoH, "2h"}, {Card::TwoD, "2d"}, {Card::TwoC, "2c"},
                                                            {Card::Unknown, "Unknown"}};

Hand::Hand(Card a, Card b)
{
    if (a < b)
        hand_ = cardToStringMap_.at(a) + cardToStringMap_.at(b);
    else
        hand_ = cardToStringMap_.at(b) + cardToStringMap_.at(a);
}

std::string Hand::getHand() const
{
    return hand_;
}
