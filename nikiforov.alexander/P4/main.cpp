#include <iostream>
#include <iomanip>
#include <string>
#include "CreateMatrix.hpp"

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
  try
  {
    if (num != 1 && num != 2)
    {
      std::cerr << "Incorrect value of the first argument\n";
      return 1;
    }
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);

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
    int* ArrMatrix;
    size_t elementsCount = 0;
    if (num == 1)
    {
      int ArrMatrix[10000] = {};
      elementsCount = matrix.inputMatrix(input, ArrMatrix, rows * cols);
      std::ofstream output(argv[3]);
      matrix.spiralMatrix(output, ArrMatrix, rows, cols);
    }
    else if (num == 2)
    {
      ArrMatrix = new int[rows * cols];
      elementsCount = matrix.inputMatrix(input, ArrMatrix, rows * cols);
      std::ofstream output(argv[3]);
      matrix.spiralMatrix(output, ArrMatrix, rows, cols);
      delete[] ArrMatrix;
    }
    if (elementsCount != rows * cols) {
      std::cerr << "Mismatch of dimension and values!\n";
      return 2;
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "One or more values are not elements of a two-dimensional array\n";
    return 2;
  }
  return 0;
}
