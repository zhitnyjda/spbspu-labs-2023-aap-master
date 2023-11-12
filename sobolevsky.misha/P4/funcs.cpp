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
  

  bool isTrianglMatrix(int * matrix, int rows, int cols)
  {

  }
}
