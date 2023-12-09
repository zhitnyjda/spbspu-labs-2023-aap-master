#include "matrix.hpp"
#include <memory>
#include <iostream>
#include <iosfwd>

size_t hohlovaa::countStrings(const int* matrix, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      if (matrix[i + rows * (j - 1)] == matrix[i + rows * j])
      {
        ++counter;
        break;
      }
    }
  }
  int res = rows - counter;
  return res;
}
