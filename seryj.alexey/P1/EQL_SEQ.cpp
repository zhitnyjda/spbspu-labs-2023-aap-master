#include "EQL_SEQ.hpp"
#include <iostream>
#include <cmath>

void eqlSeq(int &lastValue, int currentValue, int &count, int &max_count)
{
  count = (lastValue == currentValue) ? count + 1 : 1;
  max_count = fmax(max_count, count);
  lastValue = currentValue;
}
