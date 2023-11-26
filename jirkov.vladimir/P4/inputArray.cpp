#include "inputArray.hpp"
#include <algorithm>
#include <fstream>
size_t Array::inputArray(std::istream & cin, int *matrix, size_t s, size_t inputElements)
{
  for (size_t i = 0; i < std::min(inputElements, s); ++i)
  {
    if (!(cin >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(inputElements, s);
}
void Array::printArray(std::ostream & cout, int *matrix, size_t m, size_t n)
{
  cout << m << " " << n << " ";
  for (size_t i = 0; i < m * n; ++i)
  {
    cout << matrix[i] << " ";
  }
}
