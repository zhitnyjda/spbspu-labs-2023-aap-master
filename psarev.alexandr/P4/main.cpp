#include <iostream>
#include <fstream>
#include "matrixFuncs.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4) {
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

  if ((taskNum != 1) && (taskNum != 2)) {
    std::cerr << "Error: Wrong first argument value!\n";
    return 1;

  } else {
    psarev::matrix Matrix;
    std::ifstream input(argv[2]);
    size_t rows = 0, cols = 0;
    if (!(input >> rows >> cols)) {
      std::cerr << "Error: Can't read input file!\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    if (!output.is_open()) {
      std::cerr << "Error: Can't open an output file!\n";
      return 2;
    }
    size_t counter = 0;

    if (taskNum == 1) {
      int stMatrix[10000] = { 0 };
      if (Matrix.inputMatrix(input, stMatrix, rows*cols, counter) != (rows*cols)) {
        std::cerr << "Error: Mismatch of dimension and values!\n";
        return 2;
      }
      int verdict = Matrix.isTriMatrix(stMatrix, rows, cols);
      verdict == 1 ? output << "true\n" : output << "false\n";

    } else if (taskNum == 2) {
      int* dynMatrix = new int[rows * cols];
      if (Matrix.inputMatrix(input, dynMatrix, rows*cols, counter) != (rows*cols)) {
        std::cerr << "Error: Mismatch of dimension and values!\n";
        delete[] dynMatrix;
        return 2;
      }
      int verdict = Matrix.isTriMatrix(dynMatrix, rows, cols);
      verdict == 1 ? output << "true\n" : output << "false\n";
      delete[] dynMatrix;
    }
  }

  return 0;
}
