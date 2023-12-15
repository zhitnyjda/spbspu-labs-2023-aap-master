#include "minSu.hpp"

int sumBeforeDiag(int * matrix, int rows)
{
  int minSum = matrix[0];
  for (int i = 0; i < (rows - 1); i++)
  {
    int locSum = 0;
    for (int j = 0; j < (1 + i); j++)
    {
      locSum += matrix[i + ((rows - 1) * j)];
    }
    minSum = locSum < minSum ? locSum : minSum;
  }
  return minSum;
}

int sumAfterDiag(int * matrix, int cols, int rows, int minSum)
{
  for (int i = cols * (cols - 1) + 1; i < rows * rows; i++)
  {
    int locSum = 0;
    for (int j = 0; j <= (cols * (cols - 1) + cols - 1 - i); j++)
    {
      locSum += matrix[i - ((rows - 1) * j)];
    }
    minSum = locSum < minSum ? locSum : minSum;
  }
  return minSum;
}

int ponomarev::minSu(int * matrix, int rows, int cols)
{
  int minSum = sumBeforeDiag(matrix, rows);
  minSum = sumAfterDiag(matrix, cols, rows, minSum);
  return minSum;
}
