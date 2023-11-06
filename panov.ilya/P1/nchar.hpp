#include "nchar.hpp"

panov::Nchar::Nchar():
  count(0), first(0)
{}

void panov::Nchar::operator()(int subsequent)
{
  if (first != 0 && subsequent != 0 && subsequent > first)
  {
    count += 1;
  }
  first = subsequent;
}

int panov::Nchar::operator()() const
{
  return count;
}
