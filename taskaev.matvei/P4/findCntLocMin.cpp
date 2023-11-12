#include "findCntLocMin.hpp"
#include <iostream>
#include <stdexcept>

int matrixStuff::locmin(int a, int b, int c, int d)
{
  return (((((a < b) ? a : b) < c) ? ((a < b) ? a : b) : c) < d )? ((((a < b) ? a : b) < c) ? ((a < b) ? a : b) : c) : d;
}

int matrixStuff::findCntLocMin(int matrix[], int rows, int cols)
{
  if ((rows <= 2) || (cols <= 2))
  {
    std::cout << "Error no CntLocMin.\n";
    return 0;
  }

  int CntLocMin = 0;
  for (int i = cols + 1; i < ((rows - 1) * cols); i++)
  {
    if ((i % cols != 0) && ((i + 1) % cols != 0))
    {
      int lineupmin = (((matrix[i - cols - 1] < matrix[i - cols]) ? matrix[i - cols - 1] : matrix[i - cols]) < matrix[i - cols + 1]) ? ((matrix[i - cols - 1] < matrix[i - cols]) ? matrix[i - cols - 1] : matrix[i - cols]) : matrix[i - cols +1];
      int linedownmin = (((matrix[i + cols - 1] < matrix[i + cols]) ? matrix[i + cols - 1] : matrix[i + cols]) < matrix[i + cols + 1]) ? ((matrix[i + cols - 1] < matrix[i + cols]) ? matrix[i + cols - 1] : matrix[i + cols]) : matrix[i + cols + 1];
      if (matrix[i] < locmin(lineupmin,linedownmin,matrix[i - 1], matrix[i +  1]))
      {
        CntLocMin = CntLocMin + 1;
      }
    }
  }
  return CntLocMin;
}
