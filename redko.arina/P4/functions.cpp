#include "functions.hpp"
#include <iostream>
#include <cctype>

bool redko::isInteger(char * str)
{
  size_t i = 0;
  while (str[i])
  {
    if (!isdigit(str[i++]))
    {
      return false;
    }
  }
  return true;
}

void redko::inputArray(std::ifstream & in, int * matrix, size_t matrixSize)
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

int redko::countCols(int * matrix, int rows, int cols)
{
  int colsWithRep = 0;
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
  int colsWithoutRep = cols - colsWithRep;
  return colsWithoutRep;
}
