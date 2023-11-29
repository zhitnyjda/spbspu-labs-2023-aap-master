#include <algorithm>
#include "functions.hpp"

int khoroshkin::isNumber(char * str)
{
  for (int i = 0; i < std::strlen(str); i++)
  {
    if (!(std::isdigit(str[i])))
    {
      return 0;
    }
  }
  return 1;
}

void khoroshkin::fillingRowsAndCols(std::ifstream & in, int & Rows, int & Cols)
{
  if (!in.is_open())
  {
    throw std::logic_error("Cannot open an output.\n");
  }
  if (!(in >> Rows >> Cols))
  {
    throw std::logic_error("Cannot read an input.\n");
  }
}

int khoroshkin::inputArray(std::ifstream & in, int * matrix, int sizeMatrix)
{
  for (int i = 0; i < sizeMatrix; i++)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return sizeMatrix;
}

long long khoroshkin::minSumOfParallelArray(int * matrix, int Rows, int Cols)
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
  if (Rows * Cols == 0)
  {
    return 0;
  }
  else
  {
    return minSum;
  }
}

void khoroshkin::fillingOutputFile(std::ofstream & out, int * matrix, int Rows, int Cols)
{
  if (!out.is_open())
  {
    throw std::logic_error("Cannot open an output.\n");
  }
  out << khoroshkin::minSumOfParallelArray(matrix, Rows, Cols);
}
