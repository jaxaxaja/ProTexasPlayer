#include <gtest/gtest.h>
#include "HandEvaluator.h"

TEST(HandEvaluatorTest, HandStrength1)
{
    std::vector<Card> flop = {Card::Ac, Card::Qc, Card::TwoD};
    HandStrength hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Js, Card::Td), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::Streight, hand.strength_);
    std::vector<size_t> res = {2,3,4,5,6};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Qs, Card::TwoC), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::TwoPair, hand.strength_);
    res = {2, 2, 12, 12, 0};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::Td), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::Pair, hand.strength_);
    res = {0, 0, 2, 4, 5};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::Qd), flop, Card::NineC, Card::Qh);
    EXPECT_EQ(HandStrength::FullHouse, hand.strength_);
    res = {2, 2, 2, 0, 0};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::NineS, Card::NineD), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::Triple, hand.strength_);
    res = {5, 5, 5, 0, 2};
    EXPECT_EQ(res, hand.handStrength_);

    flop = {Card::Kc, Card::Ts, Card::TwoS};
    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Js, Card::SevenD), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::Streight, hand.strength_);
    res = {3, 4, 5, 6, 7};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::ThreeS, Card::SevenD), flop, Card::NineC, Card::EightD);
    EXPECT_EQ(HandStrength::HighCard, hand.strength_);
    res = {1, 4, 5, 6, 7};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Js, Card::SevenS), flop, Card::NineC, Card::EightS);
    EXPECT_EQ(HandStrength::Flush, hand.strength_);
    res = {3, 4, 6, 7, 12};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::SevenS), flop, Card::Ks, Card::EightS);
    EXPECT_EQ(HandStrength::Flush, hand.strength_);
    res = {0, 1, 4, 6, 7};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Tc, Card::Td), flop, Card::NineC, Card::Th);
    EXPECT_EQ(HandStrength::Quads, hand.strength_);
    res = {4,4,4,4,1};
    EXPECT_EQ(res, hand.handStrength_);

    flop = {Card::Ad, Card::Ac, Card::FiveS};
    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Tc, Card::Td), flop, Card::NineC, Card::NineD);
    EXPECT_EQ(HandStrength::TwoPair, hand.strength_);
    res = {0,0,4,4,5};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Tc, Card::Td), flop, Card::FiveC, Card::Jd);
    EXPECT_EQ(HandStrength::TwoPair, hand.strength_);
    res = {0,0,4,4,3};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::Ah), flop, Card::FiveC, Card::FiveD);
    EXPECT_EQ(HandStrength::Quads, hand.strength_);
    res = {0,0,0,0,9};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::Ah), flop, Card::Jc, Card::Jd);
    EXPECT_EQ(HandStrength::Quads, hand.strength_);
    res = {0,0,0,0,3};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::As, Card::Ah), flop, Card::Tc, Card::FiveD);
    EXPECT_EQ(HandStrength::Quads, hand.strength_);
    res = {0,0,0,0,4};
    EXPECT_EQ(res, hand.handStrength_);

    flop = {Card::Ac, Card::Qc, Card::Tc};
    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::Kc, Card::Jc), flop, Card::Td, Card::Jd);
    EXPECT_EQ(HandStrength::StraightFlush, hand.strength_);
    res = {0,1,2,3,4};
    EXPECT_EQ(res, hand.handStrength_);

    hand = HandEvaluator::getInstance().getHandStrength(Hand(Card::NineC, Card::Jc), flop, Card::EightC, Card::Jd);
    EXPECT_EQ(HandStrength::StraightFlush, hand.strength_);
    res = {2,3,4,5,6};
    EXPECT_EQ(res, hand.handStrength_);
}

TEST(HandEvaluatorTest, HandComparison)
{
    std::vector<size_t> res1 = {0,0,0,0,0};
    HandStrength h1(HandStrength::HighCard, res1);
    std::vector<size_t> res2 = {0,0,0,0,0};
    HandStrength h2(HandStrength::Pair, res2);
    EXPECT_TRUE(h2 > h1);
    res1 = {4,4,8,8,1};
    HandStrength h3(HandStrength::TwoPair, res1);
    res2 = {4,4,8,8,0};
    HandStrength h4(HandStrength::TwoPair, res2);
    EXPECT_TRUE(h4 > h3);
    res1 = {4,4,4,8,8};
    HandStrength h5(HandStrength::FullHouse, res1);
    res2 = {4,4,4,8,8};
    HandStrength h6(HandStrength::FullHouse, res2);
    EXPECT_TRUE(h5 == h6);
    res1 = {4,4,4,1,2};
    HandStrength h7(HandStrength::Triple, res1);
    res2 = {5,5,5,8,0};
    HandStrength h8(HandStrength::Triple, res2);
    EXPECT_TRUE(h7 > h8);
    res1 = {2,2,2,2,0};
    HandStrength h9(HandStrength::Quads, res1);
    res2 = {2,2,2,2,0};
    HandStrength h10(HandStrength::Quads, res2);
    EXPECT_TRUE(h9 == h10);
}
