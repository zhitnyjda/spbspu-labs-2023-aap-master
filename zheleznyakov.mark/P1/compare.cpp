#include "functions.hpp"

namespace zheleznyakov {
  void compareCurrentAndPrevious(int &counter, int &currentValue, int &previousValue)
  {
    if (previousValue != 0 && currentValue != 0 && currentValue > previousValue)
    {
      counter++;
    }
    previousValue = currentValue;
  }
}
