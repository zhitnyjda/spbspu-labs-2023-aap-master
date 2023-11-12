#include "matrix.hpp"
#include <iostream>
#include <memory>
#include <limits>

void sukacheva::freeMatrix(int** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int** sukacheva::createMatrix(size_t rows, size_t cols)
{
  int** rowsPtrs = new int* [rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsPtrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsPtrs[i] = new int[cols];
    }
    return rowsPtrs;
  }
  catch (const std::bad_alloc& e)
  {
    freeMatrix(rowsPtrs, rows);
    throw;
  }
}

size_t sukacheva::MaxSideDiagonal(int matrix[], size_t cols, size_t rows)
{
  if (cols != rows)
  {
    std::cerr << "There is no solution for this matrix.\n";
    return 2;
  }
  size_t maxDiagonal = (std::numeric_limits< long long > ::min());
  for (int i = 0; i < (2 * (cols - 1)); i++)
  {
    size_t diagonal = 0;
    int index = i;
    for (int j = 0; j <= i; j++)
    {
      diagonal = diagonal + matrix[index];
      index += cols - 1;
    }
    if (diagonal > maxDiagonal)
    {
      maxDiagonal = diagonal;
    }
  }
  return maxDiagonal;
}
