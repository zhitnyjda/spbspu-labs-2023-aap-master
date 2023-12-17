#ifndef MATRIX_CHECK_HPP
#define MATRIX_CHECK_HPP
#include <cstddef>

namespace gorbunova
{
  int isUpperTriangular(int matrix[100][100], size_t rows, size_t cols);
  int isUpperTriangular(int** matrix, size_t rows, size_t cols);
}
#endif
