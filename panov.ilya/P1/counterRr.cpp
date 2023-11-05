#include "counterRr.hpp"

Panov::CounterRr::CounterRr() :
    count(0), first(0)
{}

void Panov::CounterRr::operator()(int subsequent)
{
  if ((first < 0 && subsequent > 0) || (first > 0 && subsequent < 0))
  {
    count += 1;
  }
first = subsequent;
}

int Panov::CounterRr::operator()() const
{
  return count;
}