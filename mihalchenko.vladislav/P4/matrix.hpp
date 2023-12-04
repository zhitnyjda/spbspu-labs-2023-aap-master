#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace mihalchenko
{
  float* createMatrix(size_t rows, size_t cols);
  void freeMatrix(float* matrix, size_t matrLength);
}
#endif // !MATRIX_HPP
