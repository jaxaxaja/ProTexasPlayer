#ifndef HAND_EVALUATOR_H
#define HAND_EVALUATOR_H

#include "Hand.h"
#include <vector>
#include <gtest/gtest.h>

class HandStrength
{
public:
    enum Strength {Nothing, HighCard, Pair, TwoPair, Triple, Streight, Flush, FullHouse, Quads, StraightFlush};
    HandStrength() : strength_(Nothing), handStrength_(5) {}
    HandStrength(Strength s, const std::vector<size_t>& v) : strength_(s), handStrength_(v) {}
    bool operator==(const HandStrength& rhs);
    bool operator>(const HandStrength& rhs);
    friend std::ostream& operator<<(std::ostream &out, const HandStrength& h);

private:
    Strength strength_;
    std::vector<size_t> handStrength_; //the best 5 cards as hand ranking
    FRIEND_TEST(HandEvaluatorTest, HandStrength1);
};

class HandEvaluator
{
    HandEvaluator() : cardRanks_(rankSize_), cardSuits_(suitSize_) {}
    const size_t rankSize_ = 13;
    const size_t suitSize_ = 4;
    std::vector<size_t> cardRanks_; //A, K, Q, J, T, 9, 8 etc.
    std::vector<size_t> cardSuits_; //Spades, Hearts, Diamond, Clubs
    using StrengthType = std::pair<bool, std::vector<size_t>>;
    StrengthType isStreightFlush(const std::vector<Card>& v);
    StrengthType isQuads();
    StrengthType isFullHouse();
    StrengthType isFlush();
    StrengthType isStreight();
    StrengthType isTriple();
    StrengthType isTwoPair();
    StrengthType isPair();
    size_t highCard(const size_t t, const size_t ini = 1);

public:
    HandEvaluator(const HandEvaluator& rhs) = delete;
    HandEvaluator& operator=(HandEvaluator& rhs) = delete;
    static HandEvaluator& getInstance() { static HandEvaluator instance; return instance; }
    HandStrength getHandStrength(Hand playerHand, const std::vector<Card>& flop, Card turn, Card river);
};

#endif //HAND_EVALUATOR_H
