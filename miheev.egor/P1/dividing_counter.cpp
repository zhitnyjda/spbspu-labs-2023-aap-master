#include <iostream>
#include <cstddef>
#include "dividing_counter.hpp"

miheev::DevidingCounter::DevidingCounter(int previous)
{
  if (previous == 0)
  {
    throw std::domain_error("Sequence starts with zero, hence it's too short");
  }
  this->previous = previous;
  this->counter = 0;
  this->seq_is_long_enough = false;
}
void miheev::DevidingCounter::operator() (int current)
{
  if (current != 0)
  {
    if (!this->seq_is_long_enough)
    {
      this->seq_is_long_enough = true;
    }
    if (current%(this->previous) == 0)
    {
      (this->counter)++;
    }
  }
  this->previous = current;
}

