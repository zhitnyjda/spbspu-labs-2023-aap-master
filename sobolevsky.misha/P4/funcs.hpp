#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <fstream>

namespace sobolevsky
{
  bool sizeMatrix(std::istream & in, int * matrix, size_t s);
  bool isTrianglMatrix(int * matrix, size_t rows, size_t cols);
}
#endif
