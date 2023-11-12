#include "matrix.hpp"
#include <memory>
#include <iostream>

int ** matrixLife::createMatrix(size_t rows, size_t cols)
{
  int ** rowsPtrs = new int *[rows];
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
  catch (const std::bad_alloc & e)
  {
    freeMatrix(rowsPtrs, rows, cols);
    throw;
  }
}

void matrixLife::freeMatrix(int ** matrix, size_t rows)
{
  if (!matrix)
  {
    std::cerr << "Alas.\n";
  }
  for (size_t i = 0; i < rows; ++i)
  {
    delete [] matrix[i];
  }
  delete [] matrix;
}

void matrixLife::freeMatrix(int ** matrix, size_t rows, size_t)
{
  freeMatrix(matrix, rows);
}
