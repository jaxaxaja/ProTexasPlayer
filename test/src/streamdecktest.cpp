#include <gtest/gtest.h>
#include <deck/StreamDeck.h>
#include "Board.h"
#include "Player.h"
#include <strategy/StreamStrategy.h>
#include "Exceptions.h"
#include <fstream>

TEST(StreamDeckTest, DealPlayersAndStreets)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck1");
        StreamDeck deck(file);
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player2 = std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player3 = std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player4 = std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));

        deck.dealCardsToPlayer(player1);
        EXPECT_EQ("Ah2s", player1->showHand());
        deck.dealCardsToPlayer(player2);
        EXPECT_EQ("KcJd", player2->showHand());
        deck.dealCardsToPlayer(player3);
        EXPECT_EQ("TsTc", player3->showHand());
        deck.dealCardsToPlayer(player4);
        EXPECT_EQ("8h4h", player4->showHand());

        deck.dealFlopCards(board);
        ASSERT_EQ(3, board.flop_.size());
        EXPECT_EQ(Card::FourD, board.flop_.front());
        EXPECT_EQ(Card::Jc, board.flop_.at(1));
        EXPECT_EQ(Card::Kh, board.flop_.back());

        deck.dealTurnCards(board);
        EXPECT_EQ(Card::Ac, board.turn_);

        deck.dealRiverCards(board);
        EXPECT_EQ(Card::Td, board.river_);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamDeckTest, BrokenPlayerCards)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck2");
        StreamDeck deck(file);
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));

        EXPECT_THROW(deck.dealCardsToPlayer(player1), PlayerHandParsingError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamDeckTest, BrokenFlop)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck3");
        StreamDeck deck(file);
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player2 = std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player3 = std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player4 = std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));

        deck.dealCardsToPlayer(player1);
        deck.dealCardsToPlayer(player2);
        deck.dealCardsToPlayer(player3);
        deck.dealCardsToPlayer(player4);
        EXPECT_THROW(deck.dealFlopCards(board), FlopParsingError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamDeckTest, BrokenTurn)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck4");
        StreamDeck deck(file);
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player2 = std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player3 = std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player4 = std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));

        deck.dealCardsToPlayer(player1);
        deck.dealCardsToPlayer(player2);
        deck.dealCardsToPlayer(player3);
        deck.dealCardsToPlayer(player4);
        deck.dealFlopCards(board);
        EXPECT_THROW(deck.dealTurnCards(board), TurnParsingError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(StreamDeckTest, BrokenRiver)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck5");
        StreamDeck deck(file);
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player2 = std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player3 = std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
        std::unique_ptr<Player> player4 = std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));

        deck.dealCardsToPlayer(player1);
        deck.dealCardsToPlayer(player2);
        deck.dealCardsToPlayer(player3);
        deck.dealCardsToPlayer(player4);
        deck.dealFlopCards(board);
        deck.dealTurnCards(board);
        EXPECT_THROW(deck.dealRiverCards(board), RiverParsingError);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}
