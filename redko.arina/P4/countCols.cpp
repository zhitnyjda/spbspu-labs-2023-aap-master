#include "countCols.hpp"

int redko::countCols(const int * matrix, int rows, int cols)
{
  int colsWithRep = 0;
  for (int i = 0; i < cols; ++i)
  {
    for (int j = 1; j < rows; ++j)
    {
      if (matrix[i + cols * (j - 1)] == matrix[i + cols * j])
      {
        colsWithRep++;
        break;
      }
    }
  }
  int colsWithoutRep = cols - colsWithRep;
  return colsWithoutRep;
}
