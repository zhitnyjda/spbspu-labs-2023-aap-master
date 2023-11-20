#include "matrix.hpp"
#include <iostream>
#include <memory>

size_t sukacheva::MaxSideDiagonal(int matrix[], size_t cols, size_t rows)
{
  size_t maxDiagonal = 0;
  size_t diagonal = 0;
  size_t index = 0;
  for (size_t i = 1; i <= (cols + rows) - 1; i++)
  {
    index = 0;
    diagonal = 0;
    (i > cols) ? (index = cols * (i + 1 - cols) - 1) : (index = i - 1);
    if (i != cols)
    {
      for (size_t j = 0; (i > cols) ? (j < (cols + rows - i)): (j < i); j++)
      {
        diagonal += matrix[index];
        index += cols - 1;
      }
      if (diagonal > maxDiagonal)
      {
        maxDiagonal = diagonal;
      }
    }
  }
  return maxDiagonal;
}
