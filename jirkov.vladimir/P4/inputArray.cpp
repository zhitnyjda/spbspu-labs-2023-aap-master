#include <fstream>
#include "inputArray.hpp"

int Array::inputArray(std::istream &input, int *matrix, int m, int n)
{
  int count = 0;
  for (int i = 0; i < m * n; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return count;
    }
    count += 1;
  }
  return count;
}

void Array::printArray(std::ostream &output, int const *matrix, int m, int n)
{
  output << m << " " << n << " ";
  for (int i = 0; i < m * n; ++i)
  {
    output << matrix[i] << " ";
  }
}
