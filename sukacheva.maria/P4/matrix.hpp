#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace sukacheva
{
  int ** createMatrix(size_t rows, size_t cols);
  void freeMatrix(int** matrix, size_t rows);
  size_t MaxSideDiagonal(int matrix[], size_t cols, size_t rows);
}
#endif
