#include <gtest/gtest.h>
#include <game/Game.h>

TEST(GameTest, activePlayers)
{
    Board board;
    std::vector<Player> players = {Player("Lukasz", board, 100), Player("Damian", board, 100), Player("Pawel", board, 100)};
    Game game(1, "0.5/1", players);
    EXPECT_EQ(3, game.activePlayers());
}
