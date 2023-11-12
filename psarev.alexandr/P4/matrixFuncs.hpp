#ifndef MATRIX_FUNCS_H
#define MATRIX_FUNCS_H
#include <cstddef>
#include <fstream>

namespace psarev
{
  class matrix
  {
  private:
    int rows;
    int cols;
    size_t cap;
    int* matrix;
  public:
    size_t inputMatrix(std::ifstream& in, int* matrix, size_t cap, size_t counter);
    bool isTriMatrix(int* matrix, int rows, int cols);
  };
}
#endif
