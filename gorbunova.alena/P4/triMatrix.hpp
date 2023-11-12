#ifndef TRIMATRIX_HPP
#define TRIMATRIX_HPP
#include <cstddef>
#include <fstream>

namespace gorbunova
{
  class matrix
  {
  public:
    size_t inputMatrix(std::ifstream& in, int* matrix, size_t mtx, size_t counter);
    bool isTriMatrix(int* matrix, int rows, int cols);
  private:
    int rows;
    int cols;
    size_t mtx;
    int* matrix;
  }
}
#endif
