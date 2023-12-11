#include <fstream>
#include "inputArray.hpp"

int Array::inputArray(std::istream &input, int *arr, int m, int n)
{
  int count = 0;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (!(input >> arr[i * n + j]))
      {
        throw std::runtime_error("Input Error");
      }
      ++count;
    }
  }
  return count;
}
void Array::printArray(std::ostream &output, const int *arr, int m, int n)
{
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      output << arr[i * n + j] << " ";
    }
    output << std::endl;
  }
}
