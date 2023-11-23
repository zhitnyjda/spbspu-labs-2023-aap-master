#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <ostream>
#include <iostream>

namespace MatrixStuff{
  size_t NumberOfDiagonals(int *matrix);
  void writeResult(std::ostream &output, int result);
  void readMatrix(std::istream &input, int *matrix, int n, int m);
}
#endif
