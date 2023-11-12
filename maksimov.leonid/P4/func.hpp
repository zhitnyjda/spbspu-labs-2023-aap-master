#ifndef FUNC_HPP
#define FUNC_HPP
#include <string>

namespace matrix
{
  void push_back(int*&, int&, const int);
  int* creatStaticMatrix(const std::string&, size_t, size_t);
  bool matrixconditionCheck(const int*, size_t, size_t);
  int printToFile(const std::string&, const std::string&);
  int readFile(const std::string&, size_t&, size_t&, std::string&);
}

#endif