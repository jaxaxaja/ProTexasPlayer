#include <gtest/gtest.h>
#include <game/Game.h>
#include <game/GameFactory.h>
#include <deck/StreamDeck.h>
#include <strategy/StreamStrategy.h>
#include <fstream>

class TestGameFactory : public GameFactory
{
    std::ifstream file;
    virtual std::unique_ptr<StrategyImpl> createHeroStrategy(const Position position) override {}
    virtual std::unique_ptr<StrategyImpl> createPlayerStrategy(const std::string &playerName = "",
                                                               const Position position = Position::EP) override
    { return std::make_unique<StreamStrategy>(file); }
public:
    TestGameFactory(const std::string& path) : file(path) {}
    virtual std::unique_ptr<DeckImpl> createDeck() override { return std::make_unique<StreamDeck>(file); }
    virtual std::vector<std::unique_ptr<Player>> createPlayers(Board& board) override
    {
        std::vector<std::unique_ptr<Player>> res;
        int num;
        file >> num;
        while (num--)
        {
            std::string name, pos;
            float bb;
            file >> name >> pos >> bb;
            Position position = pos == "BU" ? Position::BU : pos == "SB" ? Position::SB : pos == "BB" ? Position::BB
                                           : pos == "EP" ? Position::EP : pos == "MP" ? Position::MP : Position ::CO;
            res.emplace_back(std::make_unique<Player>(name, board, bb, position, createPlayerStrategy()));
        }
        return res;
    }
    virtual ~TestGameFactory() = default;
};

TEST(GameTest, GameSimulation1)
{
    try {
        std::unique_ptr<GameFactory> factory = std::make_unique<TestGameFactory>("/home/sg222629/repos/ProTexasPlayer/test/files/Game1");
        std::unique_ptr<DeckImpl> deck = factory->createDeck();
        Game game(deck, factory);
        EXPECT_NO_THROW(game.playHand());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(GameTest, GameSimulation2)
{
    try {
        std::unique_ptr<GameFactory> factory = std::make_unique<TestGameFactory>("/home/sg222629/repos/ProTexasPlayer/test/files/Game2");
        std::unique_ptr<DeckImpl> deck = factory->createDeck();
        Game game(deck, factory);
        EXPECT_NO_THROW(game.playHand());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(GameTest, GameSimulation3)
{
    try {
        std::unique_ptr<GameFactory> factory = std::make_unique<TestGameFactory>("/home/sg222629/repos/ProTexasPlayer/test/files/Game3");
        std::unique_ptr<DeckImpl> deck = factory->createDeck();
        Game game(deck, factory);
        EXPECT_NO_THROW(game.playHand());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(GameTest, GameSimulation4)
{
    try {
        std::unique_ptr<GameFactory> factory = std::make_unique<TestGameFactory>("/home/sg222629/repos/ProTexasPlayer/test/files/Game4");
        std::unique_ptr<DeckImpl> deck = factory->createDeck();
        Game game(deck, factory);
        EXPECT_NO_THROW(game.playHand());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}
