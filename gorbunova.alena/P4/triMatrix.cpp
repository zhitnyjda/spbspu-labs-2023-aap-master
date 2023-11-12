#include "triMatrix.hpp"
#include <iostream>

namespace gorbunova
{
  size_t matrix::inputMatrix(std::ifstream& in, int* matrix, size_t mtx, size_t counter)
  {
    for (size_t x = 0; x < mtx; x++)
    {
      if (!(in >> matrix[x]))
      {
        return x;
      }
      counter++;
    }
    return counter;
  }
  bool matrix::isTriMatrix(int* matrix, int rows, int cols)
  {
    for (int x = 1; x < rows; x++)
    {
      for (int y = 0; y < x; y++)
      {
        if (matrix[x * cols + y] != 0)
        {
          return false;
        }
      }
    }
    return true;
  }
}
