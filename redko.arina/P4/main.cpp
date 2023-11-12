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
  if (num == 1)
  {
    redko::matrix Matrix;
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
    try
    {
      Matrix.inputArray(input, staticMatrix, rows * cols);
    }
    catch (std::runtime_error & e)
    {
      std::cerr << e.what();
      return 2;
    }
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "can't output\n";
      return 2;
    }
    output << Matrix.countCols(staticMatrix, rows, cols) << '\n';
    return 0;
  }
  else if (num == 2)
  {
    redko::matrix Matrix;
    int rows = 0;
    int cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "can't read input\n";
      return 2;
    }
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
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "can't output\n";
      return 2;
    }
    output << Matrix.countCols(dynamicMatrix, rows, cols) << '\n';
    delete[] dynamicMatrix;
    return 0;
  }
  std::cerr << "wrong first argument\n";
  return 1;
}
