#include "maxchetn.hpp"
#include <limits>
#include <stdexcept>

void litsinger::count_max::operator()(int value)
{
  const int maxSize = std::numeric_limits< int >::max();
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
