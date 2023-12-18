#ifndef MATRIX_ACTIONS_HPP
#define MATRIX_ACTIONS_HPP
#include "point.hpp"
#include <fstream>

namespace likhachev
{
  void inputMatrixFromFile(Point size, std::ifstream& inStream, int* values);
  void outputMatrixToFile(Point size, std::ofstream& outStream, int* values);

  void changeMatrixWithSpiral(Point size, int* values);
  int countNonRepeatColumns(Point size, int* values);
};
#endif
