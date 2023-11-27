#include "funcs.hpp"
#include <iostream>

namespace sobolevsky
{
  size_t sizeMatrix(std::istream & in, int * matrix, size_t s, size_t counter)
  {
    for (size_t i = 0; i < s; ++i)
    {
      if (in >> matrix[i])
      {
        counter++;
      }
    }
    return counter;
  }

  bool isTrianglMatrix(int * matrix, size_t rows, size_t cols)
  {
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t k = 0; k < cols; k++)
      {
        if ((matrix[k*cols + i] != 0) && (i > k))
        {
          return false;
        }
      }
    }
    return true;
  }
}
