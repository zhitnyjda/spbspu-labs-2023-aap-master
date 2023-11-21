#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <ostream>


namespace matrixStuff
{
  size_t NumberOfDiagonals(int * matrix);
  void writeResult(std::ostream& output, int result);
  void readMatrix(std::istream& cin, int * matrix, int n, int m);
}
#endif
