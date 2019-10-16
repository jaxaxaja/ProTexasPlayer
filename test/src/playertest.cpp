#include <gtest/gtest.h>
#include "Player.h"
#include <strategy/StreamStrategy.h>
#include <fstream>

TEST(PlayerTest, makeMove1)
{
    Board board;
    std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/PlayerMove1");
    Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
    Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
    Player player3("Pawel", board, 100, Position::CO, std::make_unique<StreamStrategy>(file));
    Player player4("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));

    //PREFLOP
    player1.setSbBetSize();
    player2.setBbBetSize();
    std::unique_ptr<Move> m = player3.makeMove(1);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(100, player3.getStackSize());
    m = player4.makeMove(1);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(100, player4.getStackSize());
    EXPECT_FLOAT_EQ(99.5, player1.getStackSize());
    m = player1.makeMove(1);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(0.5, m->moveSize());
    EXPECT_FLOAT_EQ(99, player1.getStackSize());
    EXPECT_FLOAT_EQ(99, player2.getStackSize());
    m = player2.makeMove(1);
    EXPECT_TRUE(m->isCheck());
    EXPECT_FLOAT_EQ(99, player2.getStackSize());
    player1.setBetSize(0);
    player2.setBetSize(0);
    //FLOP
    m = player1.makeMove(0);
    EXPECT_TRUE(m->isBet());
    EXPECT_FLOAT_EQ(94, player1.getStackSize());
    m = player2.makeMove(5);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(84, player2.getStackSize());
    m = player1.makeMove(15);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(10, m->moveSize());
    EXPECT_FLOAT_EQ(84, player1.getStackSize());
    player1.setBetSize(0);
    player2.setBetSize(0);
    //TURN
    m = player1.makeMove(0);
    EXPECT_TRUE(m->isCheck());
    EXPECT_FLOAT_EQ(84, player1.getStackSize());
    m = player2.makeMove(0);
    EXPECT_TRUE(m->isBet());
    EXPECT_FLOAT_EQ(59, player2.getStackSize());
    m = player1.makeMove(25);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(84, player1.getStackSize());
}

TEST(PlayerTest, makeMove2)
{
    Board board;
    std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/PlayerMove2");
    Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
    Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
    Player player3("Pawel", board, 100, Position::CO, std::make_unique<StreamStrategy>(file));
    Player player4("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));

    //PREFLOP
    player1.setSbBetSize();
    player2.setBbBetSize();
    std::unique_ptr<Move> m = player3.makeMove(1);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(98, player3.getStackSize());
    m = player4.makeMove(2);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(94, player4.getStackSize());
    m = player1.makeMove(6);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(85, player1.getStackSize());
    m = player2.makeMove(15);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(99, player2.getStackSize());
    m = player3.makeMove(15);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(13, m->moveSize());
    EXPECT_FLOAT_EQ(85, player3.getStackSize());
    m = player4.makeMove(15);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(85, player4.getStackSize());
    player1.setBetSize(0);
    player3.setBetSize(0);
    player4.setBetSize(0);
    //FLOP
    m = player1.makeMove(0);
    EXPECT_TRUE(m->isBet());
    EXPECT_FLOAT_EQ(82, player1.getStackSize());
    m = player3.makeMove(3);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(3, m->moveSize());
    EXPECT_FLOAT_EQ(82, player3.getStackSize());
    m = player4.makeMove(3);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(70, player4.getStackSize());
    m = player1.makeMove(15);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(35, player1.getStackSize());
    m = player3.makeMove(50);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(82, player3.getStackSize());
    m = player4.makeMove(50);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(35, m->moveSize());
    EXPECT_FLOAT_EQ(35, player4.getStackSize());
}

TEST(PlayerTest, makeMove3)
{
    Board board;
    std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/PlayerMove3");
    Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
    Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
    Player player3("Pawel", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));

    //PREFLOP
    player1.setSbBetSize();
    player2.setBbBetSize();
    std::unique_ptr<Move> m = player3.makeMove(1);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(98, player3.getStackSize());
    m = player1.makeMove(2);
    EXPECT_TRUE(m->isFold());
    EXPECT_FLOAT_EQ(99.5, player1.getStackSize());
    m = player2.makeMove(2);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(1, m->moveSize());
    EXPECT_FLOAT_EQ(98, player2.getStackSize());
    player2.setBetSize(0);
    player3.setBetSize(0);
    //FLOP
    m = player2.makeMove(0);
    EXPECT_TRUE(m->isCheck());
    EXPECT_FLOAT_EQ(98, player2.getStackSize());
    m = player3.makeMove(0);
    EXPECT_TRUE(m->isBet());
    EXPECT_FLOAT_EQ(95, player3.getStackSize());
    m = player2.makeMove(3);
    EXPECT_TRUE(m->isRaise());
    EXPECT_FLOAT_EQ(87.5, player2.getStackSize());
    m = player3.makeMove(10.5);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(7.5, m->moveSize());
    EXPECT_FLOAT_EQ(87.5, player3.getStackSize());
    player2.setBetSize(0);
    player3.setBetSize(0);
    //TURN
    m = player2.makeMove(0);
    EXPECT_TRUE(m->isBet());
    EXPECT_FLOAT_EQ(69.4, player2.getStackSize());
    m = player3.makeMove(18.1);
    EXPECT_TRUE(m->isCall());
    EXPECT_FLOAT_EQ(18.1, m->moveSize());
    EXPECT_FLOAT_EQ(69.4, player3.getStackSize());
    player2.setBetSize(0);
    player3.setBetSize(0);
    //RIVER
    m = player2.makeMove(0);
    EXPECT_TRUE(m->isCheck());
    EXPECT_FLOAT_EQ(69.4, player2.getStackSize());
    m = player3.makeMove(0);
    EXPECT_TRUE(m->isCheck());
    EXPECT_FLOAT_EQ(69.4, player3.getStackSize());
}
