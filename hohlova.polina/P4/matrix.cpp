#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <memory>

size_t hohlova::matrix::inputArray(std::ifstream& in, int* matrix, size_t sizem, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, sizem); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(toRead, sizem);
}

int** hohlova::matrix::createMatrix(size_t rows, size_t cols)
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
    freeMatrix(rowsPtrs, rows, cols);
    throw;
  }
}

void hohlova::matrix::freeMatrix(int** matrix, size_t rows)
{
  if (!matrix)
  {
    std::cerr << "Alas.\n";
    return 1;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void hohlova::matrix::freeMatrix(int** matrix, size_t rows, size_t cols)
{
  freeMatrix(matrix, rows);
}

size_t hohlova::matrix::countRows(int currRow, int currCol)
{
  size_t countRows = 0;
  int currRow = rows;
  int currCol = cols;
  for (int i = 0; i <= currRow; ++i)
  {
    for (int j = 0; j <= currCol; ++j)
    {
      if (j >= 0 && j < cols && i >= 0 && i < rows && matrix[i][j] == matrix[i + 1][j])
      {
        countRows++;
      }
    }
  }
  return countRows;
}
