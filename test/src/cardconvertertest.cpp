#include <gtest/gtest.h>
#include "CardConverter.h"

TEST(CardConverterTest, CardFromString)
{
    Card c1 = CardConverter::CardFromString("Ah");
    EXPECT_EQ(Card::Ah, c1);
    Card c2 = CardConverter::CardFromString("2s");
    EXPECT_EQ(Card::TwoS, c2);
    Card c3 = CardConverter::CardFromString("8c");
    EXPECT_EQ(Card::EightC, c3);
    Card c4 = CardConverter::CardFromString("Td");
    EXPECT_EQ(Card::Td, c4);
    Card c5 = CardConverter::CardFromString("5s");
    EXPECT_EQ(Card::FiveS, c5);
    Card c6 = CardConverter::CardFromString("Tx");
    EXPECT_EQ(Card::Unknown, c6);
    Card c7 = CardConverter::CardFromString("z");
    EXPECT_EQ(Card::Unknown, c7);
}

TEST(CardConverterTest, HandFromString)
{
    Hand h1 = CardConverter::HandFromString("KdKh");
    EXPECT_EQ("KhKd", h1.getHand());
    Hand h2 = CardConverter::HandFromString("3c6d");
    EXPECT_EQ("6d3c", h2.getHand());
    Hand h3 = CardConverter::HandFromString("8c7d");
    EXPECT_EQ("8c7d", h3.getHand());
    Hand h4 = CardConverter::HandFromString("9cJs");
    EXPECT_EQ("Js9c", h4.getHand());
    Hand h5 = CardConverter::HandFromString("Qh4h");
    EXPECT_EQ("Qh4h", h5.getHand());
    Hand h6 = CardConverter::HandFromString("TsxTd");
    EXPECT_EQ("TsUnknown", h6.getHand());
    Hand h7 = CardConverter::HandFromString("a");
    EXPECT_EQ("UnknownUnknown", h7.getHand());
}

TEST(CardConverterTest, FlopFromString)
{
    std::vector<Card> f1 = CardConverter::FlopFromString("KdKhAs");
    ASSERT_EQ(3u, f1.size());
    EXPECT_EQ(Card::Kd, f1.front());
    EXPECT_EQ(Card::Kh, f1.at(1));
    EXPECT_EQ(Card::As, f1.back());
    std::vector<Card> f2 = CardConverter::FlopFromString("4c5s6s");
    ASSERT_EQ(3u, f2.size());
    EXPECT_EQ(Card::FourC, f2.front());
    EXPECT_EQ(Card::FiveS, f2.at(1));
    EXPECT_EQ(Card::SixS, f2.back());
    std::vector<Card> f3 = CardConverter::FlopFromString("8c7d");
    ASSERT_EQ(3, f3.size());
    EXPECT_EQ(Card::EightC, f3.front());
    EXPECT_EQ(Card::SevenD, f3.at(1));
    EXPECT_EQ(Card::Unknown, f3.back());
    std::vector<Card> f4 = CardConverter::FlopFromString("TsxTdc");
    ASSERT_EQ(3, f4.size());
    EXPECT_EQ(Card::Ts, f4.front());
    EXPECT_EQ(Card::Unknown, f4.at(1));
    EXPECT_EQ(Card::Unknown, f4.back());
}
