#include "cntLocMax.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main(int argc, char** argv)
{
  using namespace doroshenko;
  try
  {
    int num = readingArguments(argc, argv);
    Matrix Matrix;
    size_t rows_;
    size_t cols_;
    size_t result;
    std::ifstream input;
    input.open(argv[2]);
    if (!input) {
      std::cerr << "File not open\n";
      return 2;
    }
    input >> rows_ >> cols_;
    if (!input)
    {
      std::cerr << "It is not number\n";
      return 2;
    }
    if (num == 1)
    {
      int* staticMatrix = { 0 };
      std::ifstream input;
      Matrix.inputArray(input, staticMatrix, rows_ * cols_);
      result = Matrix.findingLocMax(staticMatrix, rows_, cols_);
    }
    else
    {
      int* dynMatrix = new int[rows_ * cols_];
      Matrix.inputArray(input, dynMatrix, rows_ * cols_);
      result = Matrix.findingLocMax(dynMatrix, rows_, cols_);
      delete[] dynMatrix;
    }
    std::ofstream output;
    output.open(argv[3]);
    if (!output) {
      std::cerr << "File not open\n";
      return 2;
    }
    output << result;
  }
  catch (const std::invalid_argument& firstError)
  {
    std::cout << firstError.what() << "\n";
    return 2;
  }
  catch (const std::logic_error& secondError)
  {
    std::cout << secondError.what() << "\n";
    return 1;
  }
}
