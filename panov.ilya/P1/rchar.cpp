#include "rchar.hpp"
panov::Rchar::Rchar() :
  count(-1), first(0), maxNumber(-32767)
{}

void panov::Rchar::operator()(int subsequent)
{
  if ((first > maxNumber))
  {
    maxNumber = first;
  }
  first = subsequent;
  if ((maxNumber >= first))
  {
    count++;
  }
}

long long panov::Rchar::operator()() const
{
  return count;
}
