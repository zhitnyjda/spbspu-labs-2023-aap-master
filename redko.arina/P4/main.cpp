#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "wrong number of arguments\n";
    return 1;
  }
  int num = 0;
  if (redko::isInteger(argv[1]))
  {
    num = std::stoll(argv[1]);
  }
  else
  {
    std::cerr << "wrong first argument\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "the first argument must be 1 or 2\n";
    return 1;
  }
  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "can't read input\n";
    return 2;
  }
  int staticMatrix[10000] = {};
  int * matrix = nullptr;
  if (num == 1)
  {
    matrix = &staticMatrix[0];
  }
  else
  {
    matrix = new int[rows * cols];
  }
  try
  {
    redko::inputArray(input, matrix, rows * cols);
  }
  catch (std::runtime_error & e)
  {
    std::cerr << e.what();
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  int result = redko::countCols(matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }
  std::ofstream output(argv[3]);
  output << result;
  return 0;
}
