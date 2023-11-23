#ifndef CREATEMATRIX_HPP
#define CREATEMATRIX_HPP
#include <cstddef>
#include <fstream>

namespace nikiforov {
  class Matrix
  {
  public:
    Matrix();
    size_t inputMatrix(std::ifstream& in, int* ArrMatrix, size_t cap);
    void spiralMatrix(std::ofstream& out, int* ArrMatrix, size_t rows, size_t cols);
  private:
    int count;
    size_t elemetscount;
  };
}
#endif
