#include "matrixCheck.hpp"
#include <iostream>

int gorbunova::isUpperTriangular(int matrix[100][100], size_t rows, size_t cols)
{
  for (int i = 1; i < rows; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (matrix[i][j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

int gorbunova::isUpperTriangular(int** matrix, size_t rows, size_t cols)
{
  for (int i = 1; i < rows; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (matrix[i][j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

