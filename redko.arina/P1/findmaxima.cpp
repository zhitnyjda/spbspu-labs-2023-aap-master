#include "findmaxima.hpp"
#include <iostream>

namespace redko
{
  void findMaxima(int& value, int& firstMaxValue, int& secondMaxValue)
  {
    if (value > firstMaxValue)
    {
      secondMaxValue = firstMaxValue;
      firstMaxValue = value;
    }
    else if (value > secondMaxValue)
    {
      secondMaxValue = value;
    }
  }
}
