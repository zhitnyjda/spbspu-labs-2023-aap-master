#include "matrixFuncs.hpp"

size_t psarev::inputMatrix(std::ifstream& in, int* matrix, size_t cap, size_t counter)
{
  for (size_t i = 0; i < cap; i++) {
    if (!(in >> matrix[i])) {
      return i;
    }
    counter++;
  }
  return counter;
}
bool psarev::isTriMatrix(int* matrix, int rows, int cols)
{
  for (int i = 1; i < rows; i++) {
    for (int k = 0; k < i; k++) {
      if (matrix[i*cols + k] != 0) {
        return false;
      }
    }
  }
  return true;
}
