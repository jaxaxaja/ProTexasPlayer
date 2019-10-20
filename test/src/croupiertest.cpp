#include <gtest/gtest.h>
#include <Croupier.h>
#include <deck/RealDeck.h>
#include <deck/StreamDeck.h>
#include <strategy/StreamStrategy.h>
#include "Exceptions.h"
#include <fstream>

TEST(CroupierTest, DealCardsFromRealDeck)
{
    Board board;
    Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
    Player player2("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
    Player player3("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
    Player player4("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));
    std::vector<Player*> players = {&player1, &player2, &player3, &player4};
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, std::move(deck));

    EXPECT_EQ(4, croupier.activePlayers());
    croupier.dealCardsToPlayers();
    EXPECT_EQ(4, player1.showHand().size());
    EXPECT_EQ(4, player2.showHand().size());
    EXPECT_EQ(4, player3.showHand().size());
    EXPECT_EQ(4, player4.showHand().size());
    EXPECT_EQ(0, board.flop_.size());
    croupier.dealFlopCards();
    EXPECT_EQ(3, board.flop_.size());
    EXPECT_TRUE(board.turn_ == Card::Unknown);
    croupier.dealTurnCards();
    EXPECT_TRUE(board.turn_ != Card::Unknown);
    EXPECT_TRUE(board.river_ == Card::Unknown);
    croupier.dealRiverCards();
    EXPECT_TRUE(board.river_ != Card::Unknown);
}

TEST(CroupierTest, DealCardsFromFile)
{
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/StreamDeck1");
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Board board;
        Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
        Player player2("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
        Player player3("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
        Player player4("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));
        std::vector<Player*> players = {&player1, &player2, &player3, &player4};
        Croupier croupier(board, players, std::move(deck));

        croupier.dealCardsToPlayers();
        EXPECT_EQ("Ah2s", player1.showHand());
        EXPECT_EQ("KcJd", player2.showHand());
        EXPECT_EQ("TsTc", player3.showHand());
        EXPECT_EQ("8h4h", player4.showHand());

        croupier.dealFlopCards();
        ASSERT_EQ(3, board.flop_.size());
        EXPECT_EQ(Card::FourD, board.flop_.front());
        EXPECT_EQ(Card::Jc, board.flop_.at(1));
        EXPECT_EQ(Card::Kh, board.flop_.back());

        croupier.dealTurnCards();
        EXPECT_EQ(Card::Ac, board.turn_);

        croupier.dealRiverCards();
        EXPECT_EQ(Card::Td, board.river_);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(CroupierTest, PreparePlayersToAct1)
{
    Board board;
    Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
    Player player2("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
    Player player3("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
    Player player4("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin));
    Player player5("Marcin", board, 100, Position::MP, std::make_unique<StreamStrategy>(std::cin));
    Player player6("Marcin", board, 100, Position::CO, std::make_unique<StreamStrategy>(std::cin));
    std::vector<Player*> players = {&player1, &player2, &player3, &player4, &player5, &player6};
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, std::move(deck));

    croupier.preparePreFlopPlayersToAct();
    ASSERT_EQ(6, croupier.playersToAct_.size());
    Player* first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::EP, first->getPosition());
    Player* last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BB, last->getPosition());

    std::queue<Player*> empty;
    std::swap(croupier.playersToAct_, empty);
    croupier.preparePostFlopPlayersToAct();
    ASSERT_EQ(6, croupier.playersToAct_.size());
    first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::SB, first->getPosition());
    last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BU, last->getPosition());
}

TEST(CroupierTest, PreparePlayersToAct2)
{
    Board board;
    Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
    Player player2("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
    Player player3("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin));
    std::vector<Player*> players = {&player1, &player2, &player3};
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, std::move(deck));

    croupier.preparePreFlopPlayersToAct();
    ASSERT_EQ(3, croupier.playersToAct_.size());
    Player* first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::BU, first->getPosition());
    Player* last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BB, last->getPosition());

    std::queue<Player*> empty;
    std::swap(croupier.playersToAct_, empty);
    croupier.preparePostFlopPlayersToAct();
    ASSERT_EQ(3, croupier.playersToAct_.size());
    first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::SB, first->getPosition());
    last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BU, last->getPosition());
}

TEST(CroupierTest, PreparePlayersToAct3)
{
    Board board;
    Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
    Player player2("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin));
    std::vector<Player*> players = {&player1, &player2};
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, std::move(deck));

    croupier.preparePreFlopPlayersToAct();
    ASSERT_EQ(2, croupier.playersToAct_.size());
    Player* first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::SB, first->getPosition());
    Player* last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BU, last->getPosition());

    std::queue<Player*> empty;
    std::swap(croupier.playersToAct_, empty);
    croupier.preparePostFlopPlayersToAct();
    ASSERT_EQ(2, croupier.playersToAct_.size());
    first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::SB, first->getPosition());
    last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::BU, last->getPosition());
}

TEST(CroupierTest, PreparePlayersToAct4)
{
    Board board;
    Player player1("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin));
    std::vector<Player*> players = {&player1};
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, std::move(deck));

    EXPECT_THROW(croupier.preparePreFlopPlayersToAct(), NoPlayerFoundError);
}

TEST(CroupierTest, AskPlayers1)
{
    Board board;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand1");
        Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
        Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
        Player player3("Pawel", board, 100, Position::EP, std::make_unique<StreamStrategy>(file));
        Player player4("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));
        std::vector<Player*> players = {&player1, &player2, &player3, &player4};
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, std::move(deck));

        //PREFLOP
        EXPECT_EQ(4, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(4, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(2, board.pot_);
        EXPECT_FLOAT_EQ(99, player1.getStackSize());
        EXPECT_FLOAT_EQ(99, player2.getStackSize());
        EXPECT_FLOAT_EQ(100, player3.getStackSize());
        EXPECT_FLOAT_EQ(100, player4.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(player1.isActive());
        EXPECT_TRUE(player2.isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(32, board.pot_);
        EXPECT_FLOAT_EQ(84, player1.getStackSize());
        EXPECT_FLOAT_EQ(84, player2.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(player1.isActive());
        EXPECT_TRUE(player2.isActive());
        //TURN
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(57, board.pot_);
        EXPECT_FLOAT_EQ(84, player1.getStackSize());
        EXPECT_FLOAT_EQ(116, player2.getStackSize());
        EXPECT_EQ(1, croupier.activePlayers());
        EXPECT_FALSE(player1.isActive());
        EXPECT_TRUE(player2.isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(CroupierTest, AskPlayers2)
{
    Board board;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand2");
        Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
        Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
        Player player3("Pawel", board, 100, Position::EP, std::make_unique<StreamStrategy>(file));
        Player player4("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));
        std::vector<Player*> players = {&player1, &player2, &player3, &player4};
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, std::move(deck));

        //PREFLOP
        EXPECT_EQ(4, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(4, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(46, board.pot_);
        EXPECT_FLOAT_EQ(85, player1.getStackSize());
        EXPECT_FLOAT_EQ(99, player2.getStackSize());
        EXPECT_FLOAT_EQ(85, player3.getStackSize());
        EXPECT_FLOAT_EQ(85, player4.getStackSize());
        EXPECT_EQ(3, croupier.activePlayers());
        EXPECT_TRUE(player1.isActive());
        EXPECT_FALSE(player2.isActive());
        EXPECT_TRUE(player3.isActive());
        EXPECT_TRUE(player4.isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(3, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(173+46, board.pot_);
        EXPECT_FLOAT_EQ(0, player1.getStackSize());
        EXPECT_FLOAT_EQ(82, player3.getStackSize());
        EXPECT_FLOAT_EQ(173+46, player4.getStackSize());
        EXPECT_EQ(0, croupier.activePlayers());
        EXPECT_FALSE(player1.isActive());
        EXPECT_FALSE(player3.isActive());
        EXPECT_FALSE(player4.isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(CroupierTest, AskPlayers3)
{
    Board board;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand3");
        Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
        Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
        Player player3("Pawel", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));
        std::vector<Player*> players = {&player1, &player2, &player3};
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, std::move(deck));

        //PREFLOP
        EXPECT_EQ(3, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(3, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(4.5, board.pot_);
        EXPECT_FLOAT_EQ(99.5, player1.getStackSize());
        EXPECT_FLOAT_EQ(98, player2.getStackSize());
        EXPECT_FLOAT_EQ(98, player3.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_FALSE(player1.isActive());
        EXPECT_TRUE(player2.isActive());
        EXPECT_TRUE(player3.isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5, board.pot_);
        EXPECT_FLOAT_EQ(87.5, player2.getStackSize());
        EXPECT_FLOAT_EQ(87.5, player3.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(player2.isActive());
        EXPECT_TRUE(player3.isActive());
        //TURN
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5+2*18.1, board.pot_);
        EXPECT_FLOAT_EQ(87.5-18.1, player2.getStackSize());
        EXPECT_FLOAT_EQ(87.5-18.1, player3.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(player2.isActive());
        EXPECT_TRUE(player3.isActive());
        //RIVER
        croupier.dealRiverCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5+2*18.1, board.pot_);
        EXPECT_FLOAT_EQ(87.5-18.1, player2.getStackSize());
        EXPECT_FLOAT_EQ(87.5-18.1, player3.getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(player2.isActive());
        EXPECT_TRUE(player3.isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}
