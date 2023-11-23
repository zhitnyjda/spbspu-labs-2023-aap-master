#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>

namespace sobolevsky
{
  size_t sizeMatrix(std::istream & in, int * matrix, size_t s);
  bool isTrianglMatrix(int * matrix, size_t rows, size_t cols);
}
#endif
