#ifndef CROUPIER_H
#define CROUPIER_H

#include <deck/DeckImpl.h>
#include "Player.h"
#include "Board.h"
#include <queue>
#include <gtest/gtest.h>

class Croupier
{
    std::unique_ptr<DeckImpl> deck_;
    Board& board_;
    std::vector<std::unique_ptr<Player>>& players_;
    std::queue<Player*> playersToAct_;
    std::vector<Player*> hypotheticalPlayers_ToAct_;
    void initializeSbAndBb(Position sb, Position bb);
    void evaluateHands(const std::vector<Player*>& players);

    FRIEND_TEST(CroupierTest, PreparePlayersToAct1);
    FRIEND_TEST(CroupierTest, PreparePlayersToAct2);
    FRIEND_TEST(CroupierTest, PreparePlayersToAct3);
    FRIEND_TEST(CroupierTest, AskPlayers1);
    FRIEND_TEST(CroupierTest, AskPlayers2);
    FRIEND_TEST(CroupierTest, AskPlayers3);

public:
    Croupier(Board& board, std::vector<std::unique_ptr<Player>>& players, std::unique_ptr<DeckImpl>& deck);
    void dealCardsToPlayers();
    void dealFlopCards();
    void dealTurnCards();
    void dealRiverCards();
    void askPlayers(float bb = 0);
    void chooseWinner();
    size_t activePlayers();
    size_t allInPlayers();
    void preparePreFlopPlayersToAct();
    void preparePostFlopPlayersToAct();
};

#endif //CROUPIER_H
