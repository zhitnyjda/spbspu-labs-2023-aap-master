#include <iostream>
#include <string>
#include "CreateMatrix.hpp"

int main(int argc, const char* argv[])
{
  if (argc != 4) {
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

  int staticArr[10000] = {};
  int* Arr = 0;

  if (num == 1)
  {
    Arr = staticArr;
  }
  else if (num == 2)
  {
    Arr = new int[rows * cols];
  }

  if (nikiforov::inputMatrix(input, Arr, rows * cols) != rows * cols)
  {
    std::cerr << "Mismatch of dimension and values!\n";
    if (num == 2) {
      delete[] Arr;
      Arr = nullptr;
    }
    return 2;
  }

  nikiforov::spiralMatrix(output, Arr, rows, cols);

  if (num == 2) {
    delete[] Arr;
    Arr = nullptr;
  }
  return 0;
}
