#include <fstream>
#include "inputArray.hpp"

size_t Array::inputArray(std::istream &input, int *matrix, size_t Size)
{
  for (size_t i = 0; i < Size; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return i;
    }
  }
  return Size;
}

void Array::printArray(std::ostream &output, int const *matrix, size_t m, size_t n)
{
  output << n << " " << m << " ";
  for (size_t i = 0; i < n * m; ++i)
  {
    output << matrix[i] << " ";
  }
}
