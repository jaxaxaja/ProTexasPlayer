#include <gtest/gtest.h>
#include <strategy/StreamStrategy.h>

TEST(StreamStrategy, GoodPlayerMoves)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/FileStrategy1");
        StreamStrategy strategy(file);
        //a jak bedziemy handlowac dwa streamy do pliku w prawdziwej grze? Filedeck i FileStrategy, moze file deck przekaze stream do strategy?
        deck.dealCardsToPlayer(&player1);
        EXPECT_EQ("Ah2s", player1.showHand());
        deck.dealCardsToPlayer(&player2);
        EXPECT_EQ("KcJd", player2.showHand());
        deck.dealCardsToPlayer(&player3);
        EXPECT_EQ("TsTc", player3.showHand());
        deck.dealCardsToPlayer(&player4);
        EXPECT_EQ("8h4h", player4.showHand());

        deck.dealFlopCards(board);
        ASSERT_EQ(3, board.flop_.size());
        EXPECT_EQ(Card::FourD, board.flop_.front());
        EXPECT_EQ(Card::Jc, board.flop_.at(1));
        EXPECT_EQ(Card::Kh, board.flop_.back());

        deck.dealTurnCards(board);
        EXPECT_EQ(Card::Ac, board.turn_);

        deck.dealRiverCards(board);
        EXPECT_EQ(Card::Td, board.river_);
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamStrategy, BrokenPlayerMoves)
{

}
