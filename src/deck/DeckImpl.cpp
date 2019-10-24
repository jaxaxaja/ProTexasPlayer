#include <deck/DeckImpl.h>
#include <deck/StreamDeck.h>
#include <deck/RealDeck.h>
#include "Exceptions.h"

std::unique_ptr<DeckImpl> DeckImpl::createDeck(const std::string& deck, std::istream& ins)
{
    if (deck == "R")
        return std::make_unique<RealDeck>();
    else if (deck == "S" || deck == "F")
        return std::make_unique<StreamDeck>(ins);
    else
        throw WrongUserInputError();
}
