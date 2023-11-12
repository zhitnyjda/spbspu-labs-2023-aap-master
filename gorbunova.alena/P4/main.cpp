#include <iostream>
#include <fstream>
#include "triMatrix.hpp"
using namespace gorbunova;

int main(int argc, char** argv)
{
  if (argc != 4)
  {
     std::cerr << "Incorrectly entered data\n";
     return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Invalid value\n";
    return 1;
  }
  if (num == 1 || num == 2)
  {
    matrix uppMatrix;
    size_t counter = 0;
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);
    if (!(input >> rows >> cols))
    {
      std::cerr << "Can't read the file\n";
      return 2;
    }
    if (!output.is_open())
    {
      std::cerr << "Can't open  the file\n";
      return 2;
    }
    if (num == 2)
    {
      int* matrixx = new int[rows * cols];
      if (uppMatrix.inputMatrix(input, matrixx, rows * cols, counter) != (rows * cols))
      {
        std::cerr << "Dismatch of dimension and values\n";
        delete[] matrixx;
        return 2;
      }
      int verdict = uppMatrix.isTriMatrix(matrixx, rows, cols);
      verdict == 1? output << "true\n" : output << "false\n";
      delete[] matrixx;
    }
    else
    {
      int statMatrix[10000] = {};
      if (uppMatrix.inputMatrix(input, statMatrix, rows * cols, counter) != (rows * cols))
      {
        std::cerr << "Dismatch of dimension and values\n";
        return 2;
      }
      int verdict = uppMatrix.isTriMatrix(statMatrix, rows, cols);
      verdict == 1? output << "true\n" : output << "false\n";
    }
    input.close();
  }
  else
  {
    std::cerr << "Incorrect value of the first argument\n";
    return 1;
  }
  return 0;
}
