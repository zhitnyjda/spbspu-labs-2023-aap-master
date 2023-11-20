#include "InputArray.hpp"
#include <algorithm>
#include <iostream>

void readMatrix::inputMatrix(std::istream& in, int* matrix, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, s); ++i)
  {
    if (!(in >> matrix[i]))
    {
      throw std::runtime_error("Can't read an matrix.\n");
    }
  }
}
