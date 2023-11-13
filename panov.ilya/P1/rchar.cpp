#include "rchar.hpp"
panov::Rchar::Rchar() :
  count(-1), first(0), max_number(-99999)
{}

void panov::Rchar::operator()(int subsequent)
{
  if ((first > max_number))
  {
    max_number = first;
  }
  first = subsequent;
  if ((max_number >= first))
  {
    count++;
  }
}

long long panov::Rchar::operator()() const
{
  return count;
}
