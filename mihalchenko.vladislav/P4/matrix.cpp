#include <iostream>
#include "matrix.hpp"

int* mihalchenko::createMatrix(size_t rows, size_t cols)
{
  int* rowsPtrs = new int[rows * cols];
  return rowsPtrs;
}

float* mihalchenko::createMatrix(size_t rows, size_t cols, int)
{
  float* rowsPtrs = new float[rows * cols];
  return rowsPtrs;
}

void mihalchenko::freeMatrix(int* matrix, size_t matrLength)
{
  if (!matrix)
  {
    std::cerr << "The matrix being deleted was not detected\n";
  }
  delete [] matrix;
}

void mihalchenko::freeMatrix(float* matrix, size_t matrLength, int)
{
  if (!matrix)
  {
    std::cerr << "The matrix being deleted was not detected\n";
  }
  delete [] matrix;
}
