#include <strategy/range/EpStaticRange.h>

EpStaticRange::EpStaticRange() : Range({Hand()},
{Hand()}, //rfi
{Hand()}, //cold call
{Hand()}, //3b bluff
{Hand()}, //3b value
{Hand()}, //vs 3b call
{Hand()}, //vs sqz call
{Hand()}, //4b bluff
{Hand()}, //4b value
{Hand()}) //broke
{}
