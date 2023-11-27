#include "cntLocMax.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main(int argc, char** argv)
{
  using namespace doroshenko;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  try
  {
    readingArguments(argv);
  }
  catch (const std::logic_error& firstError)
  {
    std::cerr << firstError.what();
    return 1;
  }
  size_t rows_;
  size_t cols_;
  long long num = readingArguments(argv);
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
      return 0;
    }
    int staticMatrix[10000] = { 0 };
    size_t readEl = inputArray(input, staticMatrix, rows_ * cols_);
    if (readEl != rows_ * cols_)
    {
      std::cerr << "Not all elements were read";
      return 2;
    }
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "File not open\n";
      return 2;
    }
    output << findingLocMax(staticMatrix, rows_, cols_);
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
      return 0;
    }
    int* dynMatrix = new int[rows_ * cols_];
    size_t readEl = inputArray(input, dynMatrix, rows_ * cols_);
    if (readEl != rows_ * cols_)
    {
      std::cerr << "Not all elements were read";
      delete[] dynMatrix;
      return 2;
    }
    std::ofstream output(argv[3]);
    if (!output)
    {
      std::cerr << "File not open\n";
      delete[] dynMatrix;
      return 2;
    }
    output << findingLocMax(dynMatrix, rows_, cols_);
    delete[] dynMatrix;
    return 0;
  }
}
