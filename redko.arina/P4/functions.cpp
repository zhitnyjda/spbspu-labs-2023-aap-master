#include "functions.hpp"
#include <iostream>

void redko::matrix::inputArray(std::ifstream & in, int * matrix, size_t matrixSize)
{
  for (size_t i = 0; i < matrixSize; ++i)
  {
    in >> matrix[i];
    if (!in)
    {
      throw std::runtime_error("error while filling array\n");
    }
  }
}

int redko::matrix::countCols(int * matrix, int rows, int cols)
{
  int colsWithRep = 0;
  int colsWithoutRep = 0;
  for (int i = 0; i < cols; ++i)
  {
    for (int j = 1; j < rows; ++j)
    {
      if (matrix[i + cols * (j - 1)] == matrix[i + cols * j])
      {
        colsWithRep += 1;
        break;
      }
    }
  }
  colsWithoutRep = cols - colsWithRep;
  return colsWithoutRep;
}
