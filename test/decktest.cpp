#include <gtest/gtest.h>
#include <../deck.h>

TEST(DeckTest, EntireDeck)
{
    EXPECT_EQ(52u, Deck::getInstance().size());
    for (Card c = Card::As; c != Card::TwoC; ++c)
        EXPECT_EQ(true, Deck::getInstance().isInDeck(c));
    EXPECT_EQ(true, Deck::getInstance().isInDeck(Card::TwoC));
}
