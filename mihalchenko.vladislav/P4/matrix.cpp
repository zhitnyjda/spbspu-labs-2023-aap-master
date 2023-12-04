#include <iostream>
#include "matrix.hpp"

float* mihalchenko::createMatrix(size_t rows, size_t cols)
{
  float* rowsPtrs = new float[rows * cols];
  return rowsPtrs;
}

void mihalchenko::freeMatrix(float* matrix, size_t matrLength)
{
  if (!matrix)
  {
    std::cerr << "The matrix being deleted was not detected\n";
  }
  delete [] matrix;
}
