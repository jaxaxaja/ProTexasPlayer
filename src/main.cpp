#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

int main(int argc, char* argv[])
{
    std::shared_ptr<spdlog::logger> stdout_logger = spdlog::stdout_color_mt("stdout");
    spdlog::set_default_logger(stdout_logger);

    spdlog::info("This is beginning of a ProTexasHoldemPlayer logging!");

    //dostaje info od AHK
    //tworzy nowa gre (Game class) z parametrami od AHK (nr rozdania, gracze, stacki, karty etc.)

    spdlog::info("End of the ProTexasHoldemPlayer logging!");
    spdlog::shutdown();
    return 0;
}
