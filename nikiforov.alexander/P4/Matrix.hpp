#ifndef MATRIX_H 
#define MATRIX_H
#include <cstddef>
#include <fstream>

namespace nikiforov
{ 
  void inputMatrix(std::ifstream& in, int* ArrMatrix, size_t cap);
  void spiralMatrix(int* ArrMatrix, size_t rows, size_t cols);
}

#endif