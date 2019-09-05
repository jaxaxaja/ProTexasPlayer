#include <gtest/gtest.h>
#include <deck/RealDeck.h>
#include <Hand.h>
#include <iostream>

TEST(RealDeckTest, EntireDeck)
{
    RealDeck deck;
    EXPECT_EQ(52u, deck.size());
    for (Card c = Card::As; c <= Card::TwoC; ++c)
        EXPECT_TRUE(deck.isInDeck(c));
}

TEST(RealDeckTest, RandomCards)
{
    RealDeck deck;
    EXPECT_EQ(52u, deck.size());
    Card c1 = deck.getRandomCard();
    EXPECT_FALSE(deck.isInDeck(c1));
    EXPECT_EQ(51u, deck.size());
    Card c2 = deck.getRandomCard();
    EXPECT_FALSE(deck.isInDeck(c2));
    EXPECT_EQ(50u, deck.size());
    Hand h(c1, c2);
    std::cout << h.getHand() << std::endl;
}
