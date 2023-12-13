#include "inputArray.hpp"
#include <fstream>

size_t sadofeva::input_ar(std::ifstream& file, int* values, size_t sz_M)
{
  int count = 0;
  while (count < sz_M)
  {
    file >> values[count];
    if (!file)
    {
      return count;
    }
    count++;
  }
  return sz_M;
}
