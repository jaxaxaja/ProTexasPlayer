#include <gtest/gtest.h>
#include <strategy/StreamStrategy.h>
#include <fstream>
#include "Exceptions.h"

TEST(StreamStrategy, GoodPlayerMoves)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy1");
        StreamStrategy strategy(file);
        Move m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Call, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Check, m.first);
        m = strategy.checkOrBet();
        EXPECT_EQ(Action::Bet, m.first);
        EXPECT_EQ(5, m.second);
        m = strategy.callRaiseOrFold(5);
        EXPECT_EQ(Action::Raise, m.first);
        EXPECT_EQ(15, m.second);
        m = strategy.callRaiseOrFold(15);
        EXPECT_EQ(Action::Call, m.first);
        EXPECT_EQ(0, m.second);
        m = strategy.checkOrBet();
        EXPECT_EQ(Action::Check, m.first);
        m = strategy.checkOrBet();
        EXPECT_EQ(Action::Bet, m.first);
        EXPECT_EQ(25, m.second);
        m = strategy.callRaiseOrFold(25);
        EXPECT_EQ(Action::Fold, m.first);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamStrategy, BrokenPreFlopMove)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy2");
        StreamStrategy strategy(file);
        Move m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        EXPECT_THROW(strategy.callRaiseOrFold(1), WrongPlayerMoveError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamStrategy, BrokenPostFlopMove)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamStrategy3");
        StreamStrategy strategy(file);
        Move m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Fold, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Call, m.first);
        m = strategy.callRaiseOrFold(1);
        EXPECT_EQ(Action::Check, m.first);
        m = strategy.checkOrBet();
        EXPECT_EQ(Action::Check, m.first);
        EXPECT_THROW(strategy.checkOrBet(), WrongPlayerMoveError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}
