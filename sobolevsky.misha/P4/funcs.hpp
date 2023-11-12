#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>

namespace sobolevsky
{
  class matrix
  {
  public:
    size_t matrix::countMatrix(std::istream & in, int * matrix, size_t s, size_t counter);
    bool isTrianglMatrix(int* matrix, int rows, int cols);
  };
}
#endif