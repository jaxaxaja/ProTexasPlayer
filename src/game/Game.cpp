#include <game/Game.h>
#include <game/PreFlop.h>
#include <spdlog/spdlog.h>

Game::Game(const std::string& stake, std::unique_ptr<DeckImpl>& deck, std::unique_ptr<GameFactory>& gameFactory)
    : stake_(stake), croupier_(board_, players_, deck)
{
    players_ = gameFactory->createPlayers(board_);
}

void Game::setGameState(GameState* state)
{
    gameState_ = state;
}

size_t Game::playersInHand()
{
    return croupier_.activePlayers() + croupier_.allInPlayers();
}

void Game::playHand()
{
    ++handNumber_;
    spdlog::info("Start of a hand! Playing hand number: {} on stake {}", handNumber_, stake_);
    setGameState(new PreFlop());

    while (playersInHand() > 1 && gameState_)
    {
        spdlog::debug("Number of active players: {}", croupier_.activePlayers());
        gameState_->dealCards(croupier_);
        gameState_->askPlayers(croupier_);
        gameState_->nextState(this);
    }
    croupier_.chooseWinner();
    spdlog::info("End of a hand! Hand number: {}", handNumber_);
}

Game::~Game()
{
    if (gameState_)
        delete gameState_;
}
