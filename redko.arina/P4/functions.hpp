#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>
namespace redko
{
  bool isInteger(char * str);
  void inputArray(std::ifstream & in, int * matrix, size_t matrixSize);
  int countCols(int * matrix, int rows, int cols);
}

#endif
