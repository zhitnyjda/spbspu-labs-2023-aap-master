#include <istream>
#include "inputArray.hpp"
size_t Array::inputArray(std::istream& input, int* matrix, size_t Size)
{
  for (size_t l = 0; l < Size; l++)
  {
    input >> matrix[l];
    if (!input)
    {
      return l;
    }
  }
  return Size;
}
