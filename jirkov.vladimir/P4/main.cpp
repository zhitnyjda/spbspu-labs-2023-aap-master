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
    return 1;
  }
  if (num != 2 || num != 1)
  {
    std::cerr << "First parameter is 1 or 2\n";
    return 1;
  }
  int m;
  int n;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Input Error\n";
    return 2;
  }
  input >> m >> n;
  if (!input)
  {
    std::cerr << "It is not number\n";
    return 2;
  }
  if (m <= 0 || n <= 0)
  {
    std::cerr << "Input Error\n";
    return 2;

  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Failed to open output file.\n";
    return 2;
  }
  int Size = m * n;
  int matrixStatic[Size];
  int *matrix = matrixStatic;
  try
  {
    if (num == 2)
    {
      int *matrixDynamic = new int[Size];
      matrix = matrixDynamic;
    }
    int inputElements = inputArray(input, matrix, Size);
    if (inputElements != Size)
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
