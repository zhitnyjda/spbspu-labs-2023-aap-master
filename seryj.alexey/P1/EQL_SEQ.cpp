#include "EQL_SEQ.hpp"
#include <iostream>
#include <cmath>

void eqlSeq(bool condition, int &count, int &max_count)
{
  count = condition ? count + 1 : 1;
  max_count = fmax(max_count, count);
}
