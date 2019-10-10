#include <strategy/FileStrategy.h>
#include <spdlog/spdlog.h>
#include "Exceptions.h"

FileStrategy::FileStrategy(const std::string &fileName) : fileName_(fileName), file_(fileName)
{
    if (!file_.good())
        throw std::ifstream::failure("Cannot open file " + fileName);
}

Move FileStrategy::callRaiseOrFold(unsigned int bb)
{
    Move m;
    if (!parser_.parsePlayerMove(&file_, m))
    {
        spdlog::error("Cannot parse player move from file: {}", fileName_);
        throw PlayerMoveParsingError();
    }

    return m;
}

Move FileStrategy::checkOrBet()
{
    Move m;
    if (!parser_.parsePlayerMove(&file_, m))
    {
        spdlog::error("Cannot parse player move from file: {}", fileName_);
        throw PlayerMoveParsingError();
    }

    return m;
}

FileStrategy::~FileStrategy()
{
    if (file_.is_open())
        file_.close();
}
