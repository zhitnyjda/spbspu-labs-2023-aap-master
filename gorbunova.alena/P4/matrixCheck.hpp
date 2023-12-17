#ifndef MATRIX_CHECK_HPP
#define MATRIX_CHECK_HPP
#include <cstddef>

namespace gorbunova
{
  int isUpperTriangular(int matrix[100][100], int rows, int cols);
  int isUpperTriangular(int** matrix, int rows, int cols);
}
#endif
