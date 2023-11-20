#include <iostream>
#include <fstream>
#include <stdexcept>
#include "function.hpp"

using namespace litsinger;
int main(int args, const char* argv[])
{
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  try
  {
    int task = litsinger::fillArguments(args, argv);
    if (task == 1)
    {
      std::ifstream input(argv[2]);
      size_t rows = 0;
      size_t cols = 0;
      input >> rows;
      input >> cols;
      if (!input.is_open())
      {
        std::cerr << "Error\n";
        return 1;
      }
      if (rows != cols)
      {
        std::cerr << "Matrix is not a square\n";
        return 1;
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
      if (!output.is_open())
      {
        std::cerr << "Can not open output file\n";
        return 1;
      }
      output << MaximalSum(static_array, rows, cols);
    }
    else if (task == 2)
    {
      size_t rows = 0;
      size_t cols = 0;
      input >> rows;
      input >> cols;
      if (!input.is_open())
      {
        std::cerr << "Error\n";
        return 1;
      }
      if (rows != cols)
      {
        std::cerr << "Matrix is not a square\n";
        return 1;
      }
      int * dynamic_array = new int[rows * cols];
      for (size_t i = 0; i < (rows * cols); i++)
      {
        input >> dynamic_array[i];
        if (!input)
        {
          std::cerr << "Input error\n";
          return 1;
          delete[] dynamic_array;
        }
      }
      if (!output.is_open())
      {
        std::cerr << "Can not open output file\n";
        delete[] dynamic_array;
      }
      output << MaximalSum(reinterpret_cast<const int*>(dynamic_array), rows, cols);
      delete[] dynamic_array;
    }
    else if (task != 1 && task != 2)
    {
      std::cerr << "Error\n";
      return 1;
    }
    return 0;
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
