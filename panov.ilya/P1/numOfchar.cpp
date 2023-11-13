#include "numOfchar.hpp"
panov::NumOfchar::NumOfchar() :
  count(0), first(0)
{}

void panov::NumOfchar::operator()(int subsequent)
{
  if ((first < 0 && subsequent > 0) || (first > 0 && subsequent < 0))
  {
    count += 1;
  }
  first = subsequent;
}

long long panov::NumOfchar::operator()() const
{
  return count;
}
