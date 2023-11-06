#include "numOfchar.hpp"

ranov::NumOfchar::NumOfchar() :
    count(0), first(0)
{}

void ranov::NumOfchar::operator()(int subsequent)
{
    if ((first < 0 && subsequent > 0) || (first > 0 && subsequent < 0))
    {
        count += 1;
    }
    first = subsequent;
}

int ranov::NumOfchar::operator()() const
{
    return count;
}
