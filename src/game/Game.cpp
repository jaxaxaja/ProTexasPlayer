#include <game/Game.h>
#include <game/PreFlop.h>
#include <spdlog/spdlog.h>

Game::Game(std::unique_ptr<DeckImpl>& deck, std::unique_ptr<GameFactory>& gameFactory)
    : croupier_(board_, players_, deck)
{
    players_ = gameFactory->createPlayers(board_, playersMoveInfo_);
}

void Game::setGameStreet(GameState* state)
{
    gameState_ = state;
}

size_t Game::playersInHand()
{
    return croupier_.activePlayers() + croupier_.allInPlayers();
}

void Game::playHand()
{
    setGameStreet(new PreFlop());

    while (playersInHand() > 1 && gameState_)
    {
        spdlog::debug("Players in hand: {}", playersInHand());
        gameState_->dealCards(croupier_);
        playersMoveInfo_.clear();
        gameState_->askPlayers(croupier_);
        gameState_->nextStreet(this);
    }
    croupier_.chooseWinner();
}

Game::~Game()
{
    if (gameState_)
        delete gameState_;
}
