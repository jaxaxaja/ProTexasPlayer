#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
#include <iostream>
#include <game/Game.h>
#include <game/GameFactory.h>
#include <game/GameSimulationFactory.h>
#include <game/RealGameFactory.h>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << "Provide starting arguments: 1 - Game simulation, 2 - Real game and stakes e.g.: 0.5/1$" << std::endl;
        return 0;
    }

    std::unique_ptr<GameFactory> gameFactory;
    const std::string option = argv[1];
    const std::string stakes = argv[2];

    if (option == "1")
        gameFactory = std::make_unique<GameSimulationFactory>();
    else if (option == "2")
        gameFactory = std::make_unique<RealGameFactory>();
    else
    {
        std::cout << "Provide starting arguments: 1 - Game simulation, 2 - Real game and stakes e.g.: 0.5/1$" << std::endl;
        return 0;
    }

    std::shared_ptr<spdlog::logger> stdout_logger = spdlog::stdout_color_mt("stdout");
    spdlog::set_default_logger(stdout_logger);
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("This is beginning of a ProTexasHoldemPlayer logging!");
    std::unique_ptr<DeckImpl> deck = gameFactory->createDeck();
    std::unique_ptr<Game> newGame = std::make_unique<Game>(stakes, deck, gameFactory);

    try {
        newGame->playHand();
    }
    catch (const std::exception& e)
    {
        spdlog::critical(e.what());
        spdlog::critical("Cannot play a hand!");
    }

    spdlog::info("End of the ProTexasHoldemPlayer logging!");
    spdlog::shutdown();
    return 0;
}
