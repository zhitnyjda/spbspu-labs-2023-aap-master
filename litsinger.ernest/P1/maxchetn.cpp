#include "maxchetn.hpp"
#include <iostream>

void litsinger::count_max::operator()(int value)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (max == 0)
  {
    max = value;
  }
  if (value == max)
  {
    counter++;
  }
  else if (max < value)
  {
    counter = 1;
    max = value;
  }
}
size_t litsinger::count_max::operator()()
{
  return counter;
}
