#include <iostream>
#include "Lessmore.hpp"

void lessmore(const int &prev, const int &curr, const int &next, int &countnum, int &countres)
{
  countnum++;
  if (countnum > 2 && curr < prev && curr > next && next != 0)
  {
    countres++;
  }
}
