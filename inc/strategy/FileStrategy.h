#ifndef FILE_STRATEGY_H
#define FILE_STRATEGY_H

#include <strategy/StrategyImpl.h>
#include "StreamParser.h"
#include <fstream>

class FileStrategy : public StrategyImpl
{
    std::ifstream file_;
    std::string fileName_;
    StreamParser parser_;

public:
    FileStrategy(const std::string& fileName);
    virtual Move checkOrBet() override;
    virtual Move callRaiseOrFold(unsigned int bb) override;
    virtual ~FileStrategy();
};

#endif //FILE_STRATEGY_H
