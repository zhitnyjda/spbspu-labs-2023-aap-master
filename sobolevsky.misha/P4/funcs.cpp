#include "funcs.hpp"
#include <iostream>

namespace sobolevsky
{
  size_t matrix::countMatrix(std::istream & in, int * matrix, size_t s, size_t counter)
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
    for (int i = 1; i < rows; i++) 
    {
      for (int k = cols; k > i; k--) 
      {
        if (matrix[i*cols + k] != 0) 
        {
          return false;
        }
      }
    }
    return true;
  }
}
