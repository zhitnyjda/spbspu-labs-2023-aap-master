#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "decreaseSpiralElements.hpp"
#include "inputArray.hpp"

int main(int argc, char** argv)
{
  using namespace jirkov;
  using namespace Array;
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
  int m = 0;
  int n = 0;
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
  if (!(input >> m >> n) || m < 0 || n < 0 || input.fail())
  {
    std::cerr << "Invalid array dimensions\n";
    return 1;
  }
  int matrixStatic[m * n];
  int *matrix = matrixStatic;
  if (m == 0 && n == 0)
  {
    printArray(output, matrix, m, n);
  }
  try
  {
    if (num == 2)
    {
      int *matrixDynamic = new int[m * n];
      matrix = matrixDynamic;
    }
    int inputElements = inputArray(input, matrix, m, n);
    if (inputElements != m * n)
    {
      throw std::logic_error("2");
    }
    printArray(output, matrix, m, n);
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
