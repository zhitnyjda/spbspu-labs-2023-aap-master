#include "cntLocMax.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main(int argc, char** argv)
{
  using namespace doroshenko;
  try
  {
    long long num = readingArguments(argc, argv);
  }
  catch(std::logic_error& firstError)
  {
    std::cerr << firstError.what();
    return 1;
  }
  Matrix Matrix;
  size_t rows_;
  size_t cols_;
  long long num = readingArguments(argc, argv);
  if (num == 1)
  {
    std::ifstream input(argv[2]);
    if (!input)
    {
      std::cerr << "File not open\n";
      return 2;
    }
    input >> rows_ >> cols_;
    if (!input)
    {
      std::cerr << "It is not number\n";
      return 2;
    }
    if (rows_ < 3 || cols_ < 3)
    {
      std::cerr << "Not enough elements\n";
      return 2;
    }
    int staticMatrix[] = { 0 };
    try
    {
      Matrix.inputArray(input, staticMatrix, rows_ * cols_);
    }
    catch (std::invalid_argument& secondError)
    {
      std::cerr << secondError.what();
      return 2;
    }
    Matrix.inputArray(input, staticMatrix, rows_ * cols_);
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "File not open\n";
      return 2;
    }
    output << Matrix.findingLocMax(staticMatrix, rows_, cols_);
    return 0;
  }
  else
  {
    std::ifstream input(argv[2]);
    if (!input)
    {
      std::cerr << "File not open\n";
      return 2;
    }
    input >> rows_ >> cols_;
    if (!input)
    {
      std::cerr << "It is not number\n";
      return 2;
    }
    if (rows_ < 3 || cols_ < 3)
    {
      std::cerr << "Not enough elements\n";
      return 2;
    }
    int* dynMatrix = new int[rows_ * cols_];
    try
    {
      Matrix.inputArray(input, dynMatrix, rows_ * cols_);
    }
    catch (std::invalid_argument& secondError)
    {
      std::cerr << secondError.what();
      return 2;
    }
    Matrix.inputArray(input, dynMatrix, rows_ * cols_);
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "File not open\n";
      return 2;
    }
    output << Matrix.findingLocMax(dynMatrix, rows_, cols_);
    delete[] dynMatrix;
    return 0;
  }
}
