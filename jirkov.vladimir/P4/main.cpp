#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "decreaseSpiralElements.hpp"
#include "inputArray.hpp"

int main(int argc, char** argv)
{
  using namespace jirkov;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  char* end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  long long len = strlen(argv[1]);
  if (end != argv[1] + len)
  {
    std::cerr << "Is not a number\n";
    return 3;
  }
  if (num != 2 && num != 1)
  {
    std::cerr << "First parameter is 1 or 2\n";
    return 2;
  }
  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Input Error\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Failed to open output file.\n";
    return 1;
  }
  if (!(input >> rows >> cols) || rows < 0 || cols < 0 || input.fail())
  {
    std::cerr << "Invalid array dimensions\n";
    return 1;
  }
  int matrixStatic[10000];
  int *matrix = matrixStatic;
  if (rows == 0 && cols == 0)
  {
    printArray(output, matrix, rows, cols);
  }
  try{
    if (num == 2)
    {
      int *matrixDynamic = new int[rows * cols];
      matrix = matrixDynamic;
    }
    int inputElements = inputArray(input, matrix, rows, cols);
    if (inputElements != rows * cols)
    {
      throw std::logic_error("2");
    }
    printArray(output, matrix, rows, cols);
    if (num == 2)
    {
      delete[] matrix;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    if (num == 2)
    {
      delete[] matrix;
      matrix = nullptr;
    }
    return 1;
  }
  matrix = nullptr;
}
