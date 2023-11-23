#include <iostream>
#include <iomanip>
#include <string>
#include "CreateMatrix.hpp"

using namespace nikiforov;

int main(int argc, const char* argv[])
{
  if (argc < 4 || argc > 4) {
    std::cerr << "Error: Not enough args.\n";
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

  if (num != 1 && num != 2) {
    std::cerr << "Incorrect value of the first argument\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  
  std::ofstream output(argv[3]);

  std::ifstream input(argv[2]);

  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read an input.\n";
    return 2;
  }
  Matrix matrix;
  int* ArrMatrix = new int[rows * cols];
  try
  {
    matrix.inputMatrix(input, ArrMatrix, rows * cols);
    matrix.spiralMatrix(ArrMatrix, rows, cols);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "One or more values are not elements of a two-dimensional array\n";
    return 2;
  }

  if (output.is_open())
  {
    output << rows << " ";
    output << cols << " ";
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
      {
        output << std::setw(4) << ArrMatrix[i * rows + j];
      }
      std::cout << "\n";
    }
  }
  delete[] ArrMatrix;
  return 0;
}
