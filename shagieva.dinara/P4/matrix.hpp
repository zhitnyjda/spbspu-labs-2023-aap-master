#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace shagieva
{
  int matrixReader(std::ifstream & input, int * values, const int numberOfValues);
  int findMaxColumn();
};

#endif
