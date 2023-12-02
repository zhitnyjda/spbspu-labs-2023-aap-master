#include "inputArray.hpp"
#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdexcept>

int main(int argc, char** argv)
{
  using namespace hohlova;
  using namespace hohlovaa;
  if (argc != 4)
  {
    std::cerr << "Something wrong, problem with number of arguments\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  int num = std::stoll(argv[1]);
  int* matrix = new int[rows * cols]
  if (num > 2 || num < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream inputFile(argv[2]);
  inputFile >> rows >> cols;
  if (!inputFile)
  {
    std::cerr << "Cannot read an input\n";
    return 2;
  }
  size_t toRead = hohlova::inputArray(inputFile, matrix, rows * cols);
  if (toRead != rows * cols)
  {
    std::cerr << "Cannot read arguments\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Cannot read an input file\n";
    return 2;
  }
  output << hohlovaa::countStrings(matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}


