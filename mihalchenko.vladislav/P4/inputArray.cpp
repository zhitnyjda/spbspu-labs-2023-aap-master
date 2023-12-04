#include <iostream>
#include "inputArray.hpp"

size_t mihalchenko::inputArray(std::istream& in, int* arrInput, size_t arrCols)
{
  for (size_t i = 0; i < arrCols; ++i)
  {
    if (!(in >> arrInput[i]))
    {
      return i;
    }
  }
  return arrCols;
}
