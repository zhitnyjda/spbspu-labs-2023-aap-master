#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace khoroshkin
{
  int isNumber(const std::string & str);
  void fillingRowsAndCols(std::ifstream & in, int & Rows, int & Cols);
  void fillingOutputFile(std::ofstream & out, int * matrix, int Rows, int Cols);
  int inputArray(std::ifstream & in, int * matrix, int sizeMatrix);
  long long minSumOfParallelArray(int * matrix, int Rows, int Cols);
}

#endif
