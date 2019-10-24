#include <game/GameSimulationFactory.h>

std::unique_ptr<StrategyImpl> GameSimulationFactory::createHeroStrategy()
{
    //stdin, file or real
    //zapytaj uzytkownika jaka strategia
    //dodac factory method do strategy
}

std::unique_ptr<StrategyImpl> GameSimulationFactory::createPlayerStrategy()
{
    //zawsze to samo co wyzej
}

std::unique_ptr<DeckImpl> GameSimulationFactory::createDeck()
{
    //zawsze to samo co wyzej
    //moze najlepiej pytac o to
    //jak file to strategy tez file
    //jak real deck to reszta stdin

}

std::vector<std::unique_ptr<Player>> GameSimulationFactory::createPlayers(Board& board)
{
    //zawsze to samo co wyzej
    //jak deck jest file to playersi tez file
    //jak deck jest real to playersi z stdin
}
