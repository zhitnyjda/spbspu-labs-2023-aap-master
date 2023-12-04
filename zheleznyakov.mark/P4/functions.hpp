#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace zheleznyakov
{
  void readMatrix(std::ifstream & input, int * matrix, int columns, int rows);
  int findMaxRowInMatrix(int * matrix, int columns, int rows);
};
#endif
