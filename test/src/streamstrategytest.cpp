#include <gtest/gtest.h>
#include <strategy/StreamStrategy.h>
#include <fstream>
#include "Exceptions.h"

TEST(StreamStrategyTest, GoodPlayerMoves)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy1");
        StreamStrategy strategy(file);
        std::unique_ptr<Move> m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isCall());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isCheck());
        m = strategy.checkOrBet();
        EXPECT_TRUE(m->isBet());
        EXPECT_EQ(5, m->moveSize());
        m = strategy.callRaiseOrFold(5);
        EXPECT_TRUE(m->isRaise());
        EXPECT_EQ(15, m->moveSize());
        m = strategy.callRaiseOrFold(15);
        EXPECT_TRUE(m->isCall());
        EXPECT_EQ(0, m->moveSize());
        m = strategy.checkOrBet();
        EXPECT_TRUE(m->isCheck());
        m = strategy.checkOrBet();
        EXPECT_TRUE(m->isBet());
        EXPECT_EQ(25, m->moveSize());
        m = strategy.callRaiseOrFold(25);
        EXPECT_TRUE(m->isFold());
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamStrategyTest, BrokenPreFlopMove)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy2");
        StreamStrategy strategy(file);
        std::unique_ptr<Move> m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        EXPECT_THROW(strategy.callRaiseOrFold(1), WrongPlayerMoveError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamStrategyTest, BrokenPostFlopMove)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy3");
        StreamStrategy strategy(file);
        std::unique_ptr<Move> m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isFold());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isCall());
        m = strategy.callRaiseOrFold(1);
        EXPECT_TRUE(m->isCheck());
        m = strategy.checkOrBet();
        EXPECT_TRUE(m->isCheck());
        EXPECT_THROW(strategy.checkOrBet(), WrongPlayerMoveError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}
