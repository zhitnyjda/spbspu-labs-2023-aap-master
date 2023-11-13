#include "funcs.hpp"
#include <iostream>

namespace sobolevsky
{
  bool matrix::countMatrix(std::istream & in, int * matrix, size_t s, size_t counter)
  {
    for (size_t i = 0; i < s; ++i)
    {
      if (!(in >> matrix[i]))
      {
        return false;
      }
    }
    return true;
  }
  

  bool matrix::isTrianglMatrix(int * matrix, size_t rows, size_t cols)
  {
    for (int i = 0; i < rows; i++) 
    {
      for (int k = 0; k < cols; k++) 
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
