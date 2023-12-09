#include "matrix.hpp"
#include <memory>
#include <iostream>
#include <iosfwd>

size_t hohlovaa::countStrings(const int* matrix, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 0; i < rows - 1; i++)
  {
    for (size_t j = 0; j < cols - 1; j++)
    {
      if (matrix[j + rows * (i - 1)] == matrix[(j + rows) * i])
      {
        ++counter;
        break;
      }
    }
  }
  int res = rows - counter;
  return res;
}
