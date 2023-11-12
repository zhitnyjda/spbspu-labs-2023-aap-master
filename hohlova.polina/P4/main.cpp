#include "matrix.hpp"
#include <iostream>
#include <fstream>
using namespace hohlova;

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong\n";
    return 1;
  }
  int num;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;
  {
    if (!input)
    {
      std::cerr << "Cannot read an input\n";
      return 2;
    }
  }
  if (num == 1)
  {
    int* matrix = new int[rows * cols];
    size_t countres = hohlova::matrix::inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Read" << countres << " elements\n";
      delete[] matrix;
      return 1;
    }
    hohlova::matrix::countRows(rows, cols);
    return 0;
  }
  if (num == 2)
  {
    int** m1 = nullptr;
    int** m2 = nullptr;
    try
    {
      m1 = hohlova::matrix::createMatrix(rows, cols);
      m2 = hohlova::matrix::createMatrix(rows, cols);
      hohlova::matrix::freeMatrix(m1, rows, cols);
      hohlova::matrix::freeMatrix(m2, rows, cols);
    }
    catch (const std::invalid_argument& e)
    {
      hohlova::matrix::freeMatrix(m1, rows, cols);
      hohlova::matrix::freeMatrix(m2, rows, cols);
      return 3;
    }
    std::ofstream output(argv[3]);
    output << rows << " " << cols << "\n";
    return 0;
  }
  else
    return 2;
  {
    std::ofstream output(argv[3]);
    output << hohlova::matrix::countRows(rows, cols) << "\n";
  }
  return 0;
  }
}
