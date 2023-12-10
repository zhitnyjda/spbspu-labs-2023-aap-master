#include <fstream>
#include "inputArray.hpp"

int Array::inputArray(std::istream &input, int *matrix, int Size)
{
  for (int i = 0; i < Size; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return i;
    }
  }
  return Size;
}

void Array::printArray(std::ostream &output, int const *matrix, int m, int n)
{
  output << n << " " << m << " ";
  for (int i = 0; i < n * m; ++i)
  {
    output << matrix[i] << " ";
  }
}
