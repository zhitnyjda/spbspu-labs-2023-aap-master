#include "CreateMatrix.hpp"
#include <iostream>
#include <string>

using namespace nikiforov;

int main(int argc, const char* argv[])
{
  if (argc < 4 || argc > 4) {
    std::cerr << "Not enough args.\n";
    return 1;
  }

  int num = 0;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "First parameter is not number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Incorrect value of the first argument\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows >> cols))
  {
    std::cerr << "Cannot read an input.\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Error: Can't open an output file!\n";
    return 2;
  }
  Matrix matrix;

  if (num == 1)
  {
    int staticArr[10000] = {};
    if (matrix.inputMatrix(input, staticArr, rows * cols) != rows * cols)
    {
      std::cerr << "Mismatch of dimension and values!\n";
      return 2;
    }
    matrix.spiralMatrix(output, staticArr, rows, cols);
  }
  else if (num == 2)
  {
    int* dynamicArr = new int[rows * cols];
    if (matrix.inputMatrix(input, dynamicArr, rows * cols) != rows * cols)
    {
      std::cerr << "Mismatch of dimension and values!\n";
      delete[] dynamicArr;
      dynamicArr = nullptr;
      return 2;
    }
    matrix.spiralMatrix(output, dynamicArr, rows, cols);
    delete[] dynamicArr;
    dynamicArr = nullptr;
  }
  return 0;
}
