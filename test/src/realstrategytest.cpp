#include <gtest/gtest.h>
#include <strategy/RealStrategy.h>
#include <strategy/PreFlopStrategy.h>
#include <strategy/FlopStrategy.h>
#include <strategy/TurnStrategy.h>
#include <strategy/RiverStrategy.h>

TEST(RealStrategyTest, CreateRealStrategy)
{
    RealStrategy strategy(Position::EP);
    Board board;
    Hand hand;
    std::vector<PlayerMoveInfo> moves;

    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<PreFlopStrategy*>(strategy.realStrategy_.get()));

    board.flop_.push_back(Card::Ac);
    board.flop_.push_back(Card::Ad);
    board.flop_.push_back(Card::As);

    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<FlopStrategy*>(strategy.realStrategy_.get()));

    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<FlopStrategy*>(strategy.realStrategy_.get()));

    board.turn_ = Card::Kc;
    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<TurnStrategy*>(strategy.realStrategy_.get()));

    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<TurnStrategy*>(strategy.realStrategy_.get()));

    board.river_ = Card::Kd;
    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<RiverStrategy*>(strategy.realStrategy_.get()));

    strategy.createRealStrategy(0, board, hand, moves);
    EXPECT_TRUE(dynamic_cast<RiverStrategy*>(strategy.realStrategy_.get()));
}

TEST(RealStrategyTest, EpPreFlopStrategy)
{
    RealStrategy strategy(Position::EP);
    Board board;
    Hand hand(Card::Ad,Card::Qd);
    std::vector<PlayerMoveInfo> moves;

    std::unique_ptr<Move> move = strategy.callRaiseOrFold(1, board, hand, moves);
    EXPECT_TRUE(move->isRaise());
    EXPECT_FLOAT_EQ(2.5, move->moveSize());

    Hand hand1(Card::EightC, Card::EightD);
    std::unique_ptr<Move> move1 = strategy.callRaiseOrFold(1, board, hand1, moves);
    EXPECT_TRUE(move1->isRaise());
    EXPECT_FLOAT_EQ(2.5, move1->moveSize());

    Hand hand2(Card::Kd, Card::Js);
    std::unique_ptr<Move> move2 = strategy.callRaiseOrFold(1, board, hand2, moves);
    EXPECT_TRUE(move2->isFold());
}

TEST(RealStrategyTest, MpPreFlopStrategy)
{

}

TEST(RealStrategyTest, CoPreFlopStrategy)
{

}

TEST(RealStrategyTest, BuPreFlopStrategy)
{

}

TEST(RealStrategyTest, SbPreFlopStrategy)
{

}

TEST(RealStrategyTest, BbPreFlopStrategy)
{

}

TEST(RealStrategyTest, CbetFlopStrategy)
{

}

TEST(RealStrategyTest, vsDonkFlopStrategy)
{

}

TEST(RealStrategyTest, CheckCallFlopStrategy)
{

}

TEST(RealStrategyTest, CheckFoldFlopStrategy)
{

}

TEST(RealStrategyTest, CheckRaiseFlopStrategy)
{

}
