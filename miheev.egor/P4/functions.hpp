#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace miheev
{
  void inputToArr(std::ifstream& in, int* arr, size_t size);
  void printArrInline(int* arr, size_t size);
  void extendStringWithArr(int* arr, size_t size, std::string&);
  std::string getIncreasedMatrixInline(int* arr, size_t rows, size_t cols);
}

#endif
