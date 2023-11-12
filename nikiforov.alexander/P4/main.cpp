#include <iostream>
#include "Matrix.hpp"
#include <iomanip>
#include <string>
using namespace nikiforov;

int main(int argc, const char* argv[])
{
  if (argc < 4) {
    std::cerr << "Error: Not enough args.\n";
    return 1;
  }
  if (argc > 4) {
    std::cerr << "Error: Too many args.\n";
    return 1;
  }

  try
  {
    int num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "First parameter is not number";
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
  int* ArrMatrix = new int[rows * cols];
  try
  {
    inputMatrix(input, ArrMatrix, rows * cols);
    spiralMatrix(ArrMatrix, rows, cols);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "One or more values are not elements of a two-dimensional array";
    return 2;
  }
 
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cout << std::setw(4) << ArrMatrix[i * rows + j];
    }
    std::cout << "\n";
  }

  if (output.is_open())
  {
    output << rows << " ";
    output << cols << " ";
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        output << std::setw(4) << ArrMatrix[i * rows + j];
      }
      std::cout << "\n";
    }
  }
  delete[] ArrMatrix;
  return 0;
}
