#include <gtest/gtest.h>
#include <game/Game.h>
#include <deck/StreamDeck.h>
#include <strategy/StreamStrategy.h>
#include <fstream>

TEST(GameTest, GameSimulation)
{
    try {
        Board board;
        std::ifstream file("/home/sg222629/repos/ProTexasPlayer/test/files/Hand1");
        Player player1("Lukasz", board, 100, Position::SB, std::make_unique<StreamStrategy>(file));
        Player player2("Damian", board, 100, Position::BB, std::make_unique<StreamStrategy>(file));
        Player player3("Pawel", board, 100, Position::EP, std::make_unique<StreamStrategy>(file));
        Player player4("Marcin", board, 100, Position::BU, std::make_unique<StreamStrategy>(file));
        std::vector<Player*> players = {&player1, &player2, &player3, &player4};
        std::unique_ptr<DeckImpl> deck = std::make_unique<StreamDeck>(file);
        Game game("0.5/1", deck);
        game.playHand();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
}
