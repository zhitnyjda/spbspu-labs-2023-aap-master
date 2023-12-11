#include <iostream>
#include <fstream>
#include "inputArray.hpp"
#include "sedlElem.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "I feel that something wrong-_-.\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value.\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Wrong first argument value, expected 1 or 2.\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;
  if (!(input >> rows >> cols))
  {
    std::cerr << "Error from reading numbers from a file.\n";
    return 2;
  }
  int fixMatrix[10000] = { 0 };
  int * matrix = (num == 2) ? new int[rows * cols] : fixMatrix;
  if (ponomarev::inputArray(input, matrix, rows * cols) != (rows * cols))
  {
    std::cerr << "The wrong input of matrix elements.\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  output << "Число седловых элементов = " << ponomarev::countingSed(matrix, rows, cols) << "\n";
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
