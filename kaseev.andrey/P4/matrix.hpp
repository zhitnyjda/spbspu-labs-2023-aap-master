#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <ostream>
#include <iostream>

namespace MatrixStuff
{
  size_t NumberOfDiagonals(int *matrixPointer, int n, int m);
  void writeResult(std::ostream &output, int result, bool UpperTriangularMatrix);
  int readMatrix(std::istream &input, int *matrixPointer, int n, int m);
  bool upperTriangularMatrix(int *matrixPointer, int n, int m);
}
#endif
