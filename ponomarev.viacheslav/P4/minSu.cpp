#include "minSu.hpp"

int ponomarev::minSu(int * matrix, int rows, int cols)
{
  if (rows == 2)
  {
    return matrix[0] > matrix[3] ? matrix[3] : matrix[0];
  }
  int minSum = 10000;
  for (int i = 0; i < (rows - 1); i++)
  {
    int locSum = 0;
    for (int j = 0; j < (1 + i); j++)
    {
      locSum += matrix[i + ((rows - 1) * j)];
    }
    minSum = locSum < minSum ? locSum : minSum;
  }
  for (int i = cols * (cols - 1) + 1; i < rows * rows; i++)
  {
    int locSum = 0;
    for (int j = 0; j <= (cols * (cols - 1) + cols - 1 - i); j++)
    {
      locSum += matrix[i - ((rows - 1) * j)];
    }
    minSum = locSum < minSum ? locSum : minSum;
  }
  if (minSum == 10000)
  {
    return 0;
  }
  return minSum;
}
