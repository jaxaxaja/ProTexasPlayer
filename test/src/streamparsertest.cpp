#include <gtest/gtest.h>
#include "StreamParser.h"
#include <sstream>

TEST(StreamParserTest, CardFromString)
{
    StreamParser parser;
    Card c;

    std::stringstream str1("Ah");
    EXPECT_TRUE(parser.parseCard(&str1, c));
    EXPECT_EQ(Card::Ah, c);

    std::stringstream str2("2s");
    EXPECT_TRUE(parser.parseCard(&str2, c));
    EXPECT_EQ(Card::TwoS, c);

    std::stringstream str3("8c");
    EXPECT_TRUE(parser.parseCard(&str3, c));
    EXPECT_EQ(Card::EightC, c);

    std::stringstream str4("Td");
    EXPECT_TRUE(parser.parseCard(&str4, c));
    EXPECT_EQ(Card::Td, c);

    std::stringstream str5("5s");
    EXPECT_TRUE(parser.parseCard(&str5, c));
    EXPECT_EQ(Card::FiveS, c);

    std::stringstream str6("Tx");
    EXPECT_FALSE(parser.parseCard(&str6, c));
    EXPECT_EQ(Card::Unknown, c);

    std::stringstream str7("z");
    EXPECT_FALSE(parser.parseCard(&str7, c));
    EXPECT_EQ(Card::Unknown, c);
}

TEST(StreamParserTest, HandFromString)
{
    StreamParser parser;
    Hand h;

    std::stringstream str1("KdKh");
    EXPECT_TRUE(parser.parsePlayerHand(&str1, h));
    EXPECT_EQ("KhKd", h.getHand());

    std::stringstream str2("3c6d");
    EXPECT_TRUE(parser.parsePlayerHand(&str2, h));
    EXPECT_EQ("6d3c", h.getHand());

    std::stringstream str3("8c7d");
    EXPECT_TRUE(parser.parsePlayerHand(&str3, h));
    EXPECT_EQ("8c7d", h.getHand());

    std::stringstream str4("9cJs");
    EXPECT_TRUE(parser.parsePlayerHand(&str4, h));
    EXPECT_EQ("Js9c", h.getHand());

    std::stringstream str5("Qh4h");
    EXPECT_TRUE(parser.parsePlayerHand(&str5, h));
    EXPECT_EQ("Qh4h", h.getHand());

    std::stringstream str6("TsxTd");
    EXPECT_FALSE(parser.parsePlayerHand(&str6, h));
    EXPECT_EQ("TsUnknown", h.getHand());

    std::stringstream str7("");
    EXPECT_FALSE(parser.parsePlayerHand(&str7, h));
    EXPECT_EQ("UnknownUnknown", h.getHand());
}

TEST(StreamParserTest, FlopFromString)
{
    StreamParser parser;
    std::vector<Card> f;

    std::stringstream str1("KdKhAs");
    EXPECT_TRUE(parser.parseFlopCards(&str1, f));
    ASSERT_EQ(3u, f.size());
    EXPECT_EQ(Card::Kd, f.front());
    EXPECT_EQ(Card::Kh, f.at(1));
    EXPECT_EQ(Card::As, f.back());

    std::stringstream str2("4c5s6s");
    EXPECT_TRUE(parser.parseFlopCards(&str2, f));
    ASSERT_EQ(3u, f.size());
    EXPECT_EQ(Card::FourC, f.front());
    EXPECT_EQ(Card::FiveS, f.at(1));
    EXPECT_EQ(Card::SixS, f.back());

    std::stringstream str3("8c7d");
    EXPECT_FALSE(parser.parseFlopCards(&str3, f));
    ASSERT_EQ(3, f.size());
    EXPECT_EQ(Card::EightC, f.front());
    EXPECT_EQ(Card::SevenD, f.at(1));
    EXPECT_EQ(Card::Unknown, f.back());

    std::stringstream str4("TsxTdc");
    EXPECT_FALSE(parser.parseFlopCards(&str4, f));
    ASSERT_EQ(3, f.size());
    EXPECT_EQ(Card::Ts, f.front());
    EXPECT_EQ(Card::Unknown, f.at(1));
    EXPECT_EQ(Card::Unknown, f.back());
}

TEST(StreamParserTest, MoveFromString)
{
    StreamParser parser;
    Move m;

    std::stringstream str1("CH");
    EXPECT_TRUE(parser.parsePlayerMove(&str1, m));
    EXPECT_EQ(Action::Check, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str2("CA");
    EXPECT_TRUE(parser.parsePlayerMove(&str2, m));
    EXPECT_EQ(Action::Call, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str3("F");
    EXPECT_TRUE(parser.parsePlayerMove(&str3, m));
    EXPECT_EQ(Action::Fold, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str4("R 9");
    EXPECT_TRUE(parser.parsePlayerMove(&str4, m));
    EXPECT_EQ(Action::Raise, m.first);
    EXPECT_EQ(9, m.second);

    std::stringstream str5("B 3");
    EXPECT_TRUE(parser.parsePlayerMove(&str5, m));
    EXPECT_EQ(Action::Bet, m.first);
    EXPECT_EQ(3, m.second);

    std::stringstream str6("CB");
    EXPECT_FALSE(parser.parsePlayerMove(&str6, m));
    EXPECT_EQ(Action::Unknown, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str7("ch");
    EXPECT_FALSE(parser.parsePlayerMove(&str7, m));
    EXPECT_EQ(Action::Unknown, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str8("B z");
    EXPECT_FALSE(parser.parsePlayerMove(&str8, m));
    EXPECT_EQ(Action::Bet, m.first);
    EXPECT_EQ(0, m.second);

    std::stringstream str9("R 12345678987654321");
    EXPECT_FALSE(parser.parsePlayerMove(&str9, m));
    EXPECT_EQ(Action::Raise, m.first);
    EXPECT_EQ(0, m.second);
}
