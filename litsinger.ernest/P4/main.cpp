#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "function.hpp"

using namespace litsinger;
int main(int args,char * argv[])
{
  if (args < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (args > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Error\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    if (rows != cols)
    {
      std::cerr << "Matrix is not a square\n";
      return 0;
    }
    int static_array[10000] = {0};
    for (size_t i = 0; i < (rows * cols); i++)
    {
      input >> static_array[i];
      if (!input)
      {
        std::cerr << "Input error\n";
        return 1;
      }
    }
    std::ofstream output(argv[3]);
    output << MaximalSum(static_array, rows, cols) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (rows != cols)
    {
      std::cerr << "Matrix is not a square\n";
      return 0;
    }
    int * dynamic_array = new int[rows * cols];
    for (size_t i = 0; i < (rows * cols); i++)
    {
      input >> dynamic_array[i];
      if (!input)
      {
        std::cerr << "Input error\n";
        delete[] dynamic_array;
        return 1;
      }
    }
    std::ofstream output(argv[3]);
    try
    {
      if (rows != cols)
      {
        std::cerr << "Matrix is not a square\n";
        delete[] dynamic_array;
        return 0;
      }
      output << MaximalSum(reinterpret_cast<const int*>(dynamic_array), rows, cols);
      delete[] dynamic_array;
    }
  }
  else
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}
