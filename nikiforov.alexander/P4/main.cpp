#include <iostream>
#include "Matrix.hpp"
#include <iomanip>
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
  size_t rows = 0, cols = 0;

  std::ofstream output(argv[3]);
  std::ifstream input(argv[2]);
  input >> rows >> cols;
    
  int* ArrMatrix = new int[rows * cols];
  inputMatrix(input, ArrMatrix, rows * cols);
  spiralMatrix(ArrMatrix, rows, cols);

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
