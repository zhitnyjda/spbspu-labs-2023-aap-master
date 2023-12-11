#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "decreaseSpiralElements.hpp"
#include "inputArray.hpp"

int main(int argc, char **argv)
{
  using namespace jirkov;
  using namespace Array;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  char *end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  long long len = std::strlen(argv[1]);
  if (end != argv[1] + len || (num != 1 && num != 2))
  {
    std::cerr << "Invalid first parameter\n";
    return 1;
  }
  int m = 0;
  int n = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Failed to open input file.\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Failed to open output file.\n";
    return 2;
  }
  if (!(input >> m >> n) || m <= 0 || n <= 0 || input.fail())
  {
    std::cerr << "Invalid array dimensions\n";
    return 2;
  }
  int *matrix = nullptr;
  int matrixStatic[m * n];
  if (num == 1)
  {
    matrix = matrixStatic;
  }
  else if (num == 2)
  {
    matrix = new int[m * n];
  }
  try
  {
    if (matrix != nullptr)
    {
      int inputElements = inputArray(input, matrix, m, n);
      if (inputElements != m * n)
      {
        throw std::logic_error("Wrong number of array elements\n");
      }
      printArray(output, matrix, m, n);
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
  delete[] matrix;
  return 0;
}
