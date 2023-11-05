#include "counterRr.hpp"

panov::CounterRr::CounterRr():
    count(0), first(0)
  {}

void panov::CounterRr::operator()(int subsequent)
{
  if ((first < 0 && subsequent > 0) || (first > 0 && subsequent < 0))
  {
    count += 1;
  }
first = subsequent;
}

int panov::CounterRr::operator()() const
{
  return count;
}