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
    std::vector<PlayerMoveInfo> playersMoveInfo;
    std::vector<std::unique_ptr<Player>> players;
    players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, deck);

    EXPECT_EQ(4, croupier.activePlayers());
    croupier.dealCardsToPlayers();
    EXPECT_EQ(4, players.front()->showHand().size());
    EXPECT_EQ(4, players.at(1)->showHand().size());
    EXPECT_EQ(4, players.at(2)->showHand().size());
    EXPECT_EQ(4, players.back()->showHand().size());
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
        std::vector<PlayerMoveInfo> playersMoveInfo;
        std::vector<std::unique_ptr<Player>> players;
        players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
        Croupier croupier(board, players, deck);

        croupier.dealCardsToPlayers();
        EXPECT_EQ("Ah2s", players.front()->showHand());
        EXPECT_EQ("KcJd", players.at(1)->showHand());
        EXPECT_EQ("TsTc", players.at(2)->showHand());
        EXPECT_EQ("8h4h", players.back()->showHand());

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
    std::vector<PlayerMoveInfo> playersMoveInfo;
    std::vector<std::unique_ptr<Player>> players;
    players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::EP, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::MP, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::CO, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, deck);

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
    std::vector<PlayerMoveInfo> playersMoveInfo;
    std::vector<std::unique_ptr<Player>> players;
    players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::BB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, deck);

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
    std::vector<PlayerMoveInfo> playersMoveInfo;
    std::vector<std::unique_ptr<Player>> players;
    players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::BU, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, deck);

    croupier.preparePreFlopPlayersToAct();
    ASSERT_EQ(2, croupier.playersToAct_.size());
    Player* first = croupier.playersToAct_.front();
    EXPECT_EQ(Position::BU, first->getPosition());
    Player* last = croupier.playersToAct_.back();
    EXPECT_EQ(Position::SB, last->getPosition());

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
    std::vector<PlayerMoveInfo> playersMoveInfo;
    std::vector<std::unique_ptr<Player>> players;
    players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(std::cin), playersMoveInfo));
    std::unique_ptr<DeckImpl> deck = std::make_unique<RealDeck>();
    Croupier croupier(board, players, deck);

    EXPECT_THROW(croupier.preparePreFlopPlayersToAct(), NoPlayerFoundError);
}

TEST(CroupierTest, AskPlayers1)
{
    Board board;
    std::vector<PlayerMoveInfo> playersMoveInfo;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand1");
        std::vector<std::unique_ptr<Player>> players;
        players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::EP, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, deck);

        //PREFLOP
        EXPECT_EQ(4, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(4, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(2, board.pot_);
        EXPECT_FLOAT_EQ(99, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(99, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(100, players.at(2)->getStackSize());
        EXPECT_FLOAT_EQ(100, players.back()->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(players.front()->isActive());
        EXPECT_TRUE(players.at(1)->isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(32, board.pot_);
        EXPECT_FLOAT_EQ(84, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(84, players.at(1)->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(players.front()->isActive());
        EXPECT_TRUE(players.at(1)->isActive());
        //TURN
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(57, board.pot_);
        croupier.chooseWinner();
        EXPECT_FLOAT_EQ(84, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(116, players.at(1)->getStackSize());
        EXPECT_EQ(1, croupier.activePlayers());
        EXPECT_FALSE(players.front()->isActive());
        EXPECT_TRUE(players.at(1)->isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(CroupierTest, AskPlayers2)
{
    Board board;
    std::vector<PlayerMoveInfo> playersMoveInfo;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand2");
        std::vector<std::unique_ptr<Player>> players;
        players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::EP, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, deck);

        //PREFLOP
        EXPECT_EQ(4, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(4, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(46, board.pot_);
        EXPECT_FLOAT_EQ(85, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(99, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(85, players.at(2)->getStackSize());
        EXPECT_FLOAT_EQ(85, players.back()->getStackSize());
        EXPECT_EQ(3, croupier.activePlayers());
        EXPECT_TRUE(players.front()->isActive());
        EXPECT_FALSE(players.at(1)->isActive());
        EXPECT_TRUE(players.at(2)->isActive());
        EXPECT_TRUE(players.back()->isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(3, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(173+46, board.pot_);
        croupier.chooseWinner();
        EXPECT_FLOAT_EQ(0, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(82, players.at(2)->getStackSize());
        EXPECT_FLOAT_EQ(173+46, players.back()->getStackSize());
        EXPECT_EQ(0, croupier.activePlayers());
        EXPECT_FALSE(players.front()->isActive());
        EXPECT_FALSE(players.at(2)->isActive());
        EXPECT_FALSE(players.back()->isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}

TEST(CroupierTest, AskPlayers3)
{
    Board board;
    std::vector<PlayerMoveInfo> playersMoveInfo;
    try {
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand3");
        std::vector<std::unique_ptr<Player>> players;
        players.emplace_back(std::make_unique<Player>("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        players.emplace_back(std::make_unique<Player>("Pawel", board, 100, Position::BU, std::make_unique<StreamStrategy>(file), playersMoveInfo));
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Croupier croupier(board, players, deck);

        //PREFLOP
        EXPECT_EQ(3, croupier.activePlayers());
        croupier.dealCardsToPlayers();
        EXPECT_FLOAT_EQ(1.5, board.pot_);
        croupier.preparePreFlopPlayersToAct();
        EXPECT_EQ(3, croupier.playersToAct_.size());
        croupier.askPlayers(1);
        EXPECT_FLOAT_EQ(4.5, board.pot_);
        EXPECT_FLOAT_EQ(99.5, players.front()->getStackSize());
        EXPECT_FLOAT_EQ(98, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(98, players.at(2)->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_FALSE(players.front()->isActive());
        EXPECT_TRUE(players.at(1)->isActive());
        EXPECT_TRUE(players.at(2)->isActive());
        //FLOP
        croupier.dealFlopCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5, board.pot_);
        EXPECT_FLOAT_EQ(87.5, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(87.5, players.at(2)->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(players.at(1)->isActive());
        EXPECT_TRUE(players.at(2)->isActive());
        //TURN
        croupier.dealTurnCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5+2*18.1, board.pot_);
        EXPECT_FLOAT_EQ(87.5-18.1, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(87.5-18.1, players.at(2)->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(players.at(1)->isActive());
        EXPECT_TRUE(players.at(2)->isActive());
        //RIVER
        croupier.dealRiverCards();
        croupier.preparePostFlopPlayersToAct();
        EXPECT_EQ(2, croupier.playersToAct_.size());
        croupier.askPlayers();
        EXPECT_FLOAT_EQ(4.5+2*10.5+2*18.1, board.pot_);
        croupier.chooseWinner();
        EXPECT_FLOAT_EQ(87.5-18.1, players.at(1)->getStackSize());
        EXPECT_FLOAT_EQ(87.5-18.1+board.pot_, players.at(2)->getStackSize());
        EXPECT_EQ(2, croupier.activePlayers());
        EXPECT_TRUE(players.at(1)->isActive());
        EXPECT_TRUE(players.at(2)->isActive());
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }
}
