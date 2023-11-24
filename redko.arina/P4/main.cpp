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
  int num;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "wrong first argument\n";
    return 1;
  }
  redko::Matrix Matrix;
  int result;
  int rows;
  int cols;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "can't read input\n";
    return 2;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "the first argument must be 1 or 2\n";
    return 1;
  }
  else if (num == 1)
  {
    int staticMatrix[10000] = {};
    try
    {
      Matrix.inputArray(input, staticMatrix, rows * cols);
    }
    catch (std::runtime_error & e)
    {
      std::cerr << e.what();
      return 2;
    }
    result = Matrix.countCols(staticMatrix, rows, cols);
  }
  else
  {
    int * dynamicMatrix = new int[rows * cols];
    try
    {
      Matrix.inputArray(input, dynamicMatrix, rows * cols);
    }
    catch (std::runtime_error & e)
    {
      std::cerr << e.what();
      delete[] dynamicMatrix;
      return 2;
    }
    result = Matrix.countCols(dynamicMatrix, rows, cols);
    delete[] dynamicMatrix;
  }
  input.close();
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "can't output\n";
    return 2;
  }
  output << result;
  output.close();
  return 0;
}
