#include "class.hpp"

namespace sobolevsky
{
  Arrays::Arrays(size_t inpSize)
  {
    size = inpSize;
    for (size_t i = 0; i < size; i++)
    {
      statArray[i] = 0;
    }
  }

  Arrays::Arrays(size_t rows, size_t cols)
  {
    dynArray = new int[cols * rows];
  }
}