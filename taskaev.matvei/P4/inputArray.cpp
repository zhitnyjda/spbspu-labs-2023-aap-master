#include "inputArray.hpp"

void readArray::inputArray(std::istream & in, int * m, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, s); ++i)
  {
    if (!(in >> m[i]))
    {
      throw std::length_error("Error matrix.");
    }
  }
}
