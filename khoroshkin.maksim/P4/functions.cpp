#include <algorithm>
#include "functions.hpp"

void khoroshkin::matrix::inputArray(std::ifstream & in, int * matrix, size_t sizeMatrix)
{
  for (size_t i = 0; i < sizeMatrix; ++i)
  {
    in >> matrix[i];
    if (!in)
    {
      throw std::runtime_error("Something wrong with filling array");
    }
  }
}

long long khoroshkin::matrix::minSumOfParallelArray(int * matrix, int Rows, int Cols)
{
  int minSum = std::numeric_limits< int >::max();
  for (int i = 1 - Rows; i < Rows; i++)
  {
    int currentSum = 0;
    for (int j = 0; j < Cols; j++)
    {
      if  ((i + j) >= 0 && (i + j) < Rows)
      {
        currentSum += matrix[(i + j) * Rows + j];
      }
    }
    minSum = std::min(currentSum, minSum);
  }
  return minSum;
}
