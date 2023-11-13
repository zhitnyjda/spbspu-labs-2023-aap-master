#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>

namespace sobolevsky
{
  class matrix
  {
  public:
    size_t rows;
    size_t cols;
    size_t s;
    int * matrix;
    bool countMatrix(std::istream & in, int * matrix, size_t s);
    bool isTrianglMatrix(int * matrix, size_t rows, size_t cols);
  };
}
#endif
