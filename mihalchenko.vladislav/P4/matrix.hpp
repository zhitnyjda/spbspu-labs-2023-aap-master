#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace mihalchenko
{
  int* createMatrix(size_t rows, size_t cols);
  float* createMatrix(size_t rows, size_t cols, int);
  void freeMatrix(int* matrix, size_t matrLength);
  void freeMatrix(float* matrix, size_t matrLength, int);
}
#endif // !MATRIX_HPP
