#include "findmax.hpp"

namespace khoroshkin
{
  void findMax(int &counter, int &maxValue, int &Value)
  {
    if (maxValue < Value)
    {
      maxValue = Value;
      counter = 0;
      counter++;
    }
    else if (maxValue == Value)
    {
      counter++;
    }
  }
}
