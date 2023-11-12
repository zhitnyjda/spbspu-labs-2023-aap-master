#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>

namespace sobolevsky
{
  class matrix
  {
  public:
    size_t countMatrix(std::ifstream& in, size_t counter);
    bool isTrianglMatrix(int* matrix, int rows, int cols);
  };
}
#endif