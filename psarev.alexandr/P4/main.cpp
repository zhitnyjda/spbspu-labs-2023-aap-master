#include <iostream>
#include <fstream>
#include "matrixFuncs.hpp"
using namespace psarev;

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong amount of parameters!\n";
    return 1;
  }

  int taskNum = 0;
  try
  {
    taskNum = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: First argument must be an integer!\n";
    return 1;
  }

  if (taskNum == 1 || taskNum == 2){
    matrix myMatrix;
    size_t counter = 0;
    size_t rows = 0, cols = 0;
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);
    if (!(input >> rows >> cols))
    {
      std::cerr << "Can't read input file!\n";
      return 2;
    }
    if (!output.is_open())
    {
      std::cerr << "Can't open an output file!\n";
      return 2;
    }

    if (taskNum == 2) {
      int* dynMatrix = new int[rows * cols];
      if (myMatrix.inputMatrix(input, dynMatrix, rows * cols, counter) != (rows*cols)){
        std::cerr << "Dismatch of dimension and values!\n";
        delete[] dynMatrix;
        return 2;
      }
      int verdict = myMatrix.isTriMatrix(dynMatrix, rows, cols);
      verdict == 1 ? output << "true\n" : output << "false\n";
      delete[] dynMatrix;
    } else {
      int stMatrix[10000] = {};
      if (myMatrix.inputMatrix(input, stMatrix, rows * cols, counter) != (rows*cols)){
        std::cerr << "Dismatch of dimension and values!\n";
        return 2;
      }
      int verdict = myMatrix.isTriMatrix(stMatrix, rows, cols);
      verdict == 1 ? output << "true\n" : output << "false\n";
    }

    input.close();
  } else {
    std::cerr << "Error: Wrong first argument value!\n";
    return 1;
  }

  return 0;
}
