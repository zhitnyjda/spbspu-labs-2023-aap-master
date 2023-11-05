#include "maxchetn.hpp"

void litsinger::count_max::operator()(int value)
{
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
