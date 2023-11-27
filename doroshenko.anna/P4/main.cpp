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
  int* Matrix = nullptr;
  if (num == 1)
  {
    int* Matrix[10000] = { 0 };
  }
  else
  {
    int* Matrix = new int[rows_ * cols_];
  }
  size_t readEl;
  readEl = inputArray(input, Matrix, rows_ * cols_);
  if (readEl != rows_ * cols_)
  {
    std::cerr << "Not all elements were read";
    if (num == 2)
    {
      delete[] Matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "File not open\n";
    if (num == 2)
    {
      delete[] Matrix;
    }
    return 2;
  }
  output << findingLocMax(Matrix, rows_, cols_);
  if (num == 2)
  {
    delete[] Matrix;
  }
  return 0;
}
