#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

int main(int argc, char* argv[])
{
    std::shared_ptr<spdlog::logger> stdout_logger = spdlog::stdout_color_mt("stdout");
    spdlog::set_default_logger(stdout_logger);

    spdlog::info("This is beginning of a ProTexasHoldemPlayer logging!");

    //std::unique_ptr<DeckImpl> deck = fabryka abstrakcyjna niech nam tworzy decka (z argc bedziemy brac)
    //const std::vector<Player*> &players,
    //jak tworzymy graczy to jeden ma byc Hero i dla niego tworzymy strategie jaka chcemy: stdin, file, real
    //reszta to docelowo bedzie ahk, ale do testow bedzie tez file i real
    //stworzyc Players graczy z odpowiednimi parametrami bazujac na deckImpl:
    //jak AhkDeck to policzyc ilu i stworzyc nowych Player1, Player2 ... etc.
    //jak RealDeck to z stdin
    //jak StramDeck to z file
    //croupier_(board_, players_, std::move(deck))

    //fabryki abstrakcyjne do tworzenia strategy i deck implementacji bazujace na argc?
    //
    //dostaje info od AHK
    //tworzy nowa gre (Game class) z parametrami od AHK (nr rozdania, gracze, stacki, karty etc.)

    spdlog::info("End of the ProTexasHoldemPlayer logging!");
    spdlog::shutdown();
    return 0;
}
