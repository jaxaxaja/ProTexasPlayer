#include <gtest/gtest.h>
#include <strategy/RealStrategy.h>
#include <strategy/PreFlopStrategy.h>
#include <strategy/FlopStrategy.h>
#include <strategy/TurnStrategy.h>
#include <strategy/RiverStrategy.h>
#include <move/Raise.h>
#include <move/Bet.h>
#include <move/Call.h>
#include <move/Check.h>

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
    std::vector<PlayerMoveInfo> emptyMoves;
    std::vector<PlayerMoveInfo> threeBetMoves;

    std::unique_ptr<Move> move = strategy.callRaiseOrFold(1, board, hand, emptyMoves);
    EXPECT_TRUE(move->isRaise());
    EXPECT_FLOAT_EQ(2.5, move->moveSize());

    //vs3b call
    threeBetMoves.emplace_back(move, Position::EP, 2.5, 97.5);
    std::unique_ptr<Move> threeBet = std::make_unique<Raise>(8.5);
    threeBetMoves.emplace_back(threeBet, Position::CO, 8.5, 92.5);
    std::unique_ptr<Move> call = strategy.callRaiseOrFold(8.5, board, hand, threeBetMoves);
    EXPECT_TRUE(call->isCall());

    Hand handAces(Card::Ac, Card::Ad);
    std::unique_ptr<Move> moveAces = strategy.callRaiseOrFold(1, board, handAces, emptyMoves);
    EXPECT_TRUE(moveAces->isRaise());
    EXPECT_FLOAT_EQ(2.5, moveAces->moveSize());

    //vs3b 4bet
    std::unique_ptr<Move> fourBet = strategy.callRaiseOrFold(8.5, board, handAces, threeBetMoves);
    EXPECT_TRUE(fourBet->isRaise());
    EXPECT_FLOAT_EQ(8.5f*2.3f, fourBet->moveSize());

    Hand hand1(Card::EightC, Card::EightD);
    std::unique_ptr<Move> move1 = strategy.callRaiseOrFold(1, board, hand1, emptyMoves);
    EXPECT_TRUE(move1->isRaise());
    EXPECT_FLOAT_EQ(2.5, move1->moveSize());

    //vs3b fold
    std::unique_ptr<Move> fold = strategy.callRaiseOrFold(8.5, board, hand1, threeBetMoves);
    EXPECT_TRUE(fold->isFold());

    //but vs sqz call
    threeBetMoves.emplace_back(call, Position::SB, 8.5, 91.5);
    std::unique_ptr<Move> call2 = strategy.callRaiseOrFold(8.5, board, hand1, threeBetMoves);
    EXPECT_TRUE(call2->isCall());

    Hand hand2(Card::Kd, Card::Js);
    std::unique_ptr<Move> move2 = strategy.callRaiseOrFold(1, board, hand2, emptyMoves);
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
