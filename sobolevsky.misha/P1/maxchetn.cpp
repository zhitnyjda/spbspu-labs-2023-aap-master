#include "maxchetn.hpp"
#include <algorithm>

void maxChetn(int &counter, int &countMax, int &number)
{
  if (number % 2 == 0 && number != 0)
  {
    counter++;
  }
  else
  {
    countMax = std::max(counter, countMax);
    counter = 0;
  }
}