#include "maxcount.hpp"
#include <iostream>
namespace litsinger
{
  void maxChetn(int& counter, int& max, int& value)
  {
    if (value > max)
    {
      max = value;
      counter = 1;
    }
    else if (value == max)
    {
      counter++;
    }
  }
}
