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
      if (!input.is_open())
      {
        std::cerr << "Error\n";
        return 2;
      }
      input >> rows;
      input >> cols;
      if (rows < 1)
      {
        std::cerr << "Error\n";
        return 2;
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
        if (!(input >> static_array[i]))
        {
          std::cerr << "Input error\n";
          return 2;
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
      if (!input.is_open())
      {
        std::cerr << "Error\n";
        return 2;
      }
      input >> rows;
      input >> cols;
      if (rows < 1)
      {
        std::cerr << "Error\n";
        return 2;
      }
      int * dynamic_array = new int[rows * cols];
      for (size_t i = 0; i < (rows * cols); i++)
      {
        input >> dynamic_array[i];
        if (!(input >> dynamic_array[i]))
        {
          std::cerr << "Input error\n";
          return 2;
        }
      }
      if (!output.is_open())
      {
        std::cerr << "Can not open output file\n";
      }
      output << MaximalSum(reinterpret_cast<const int*>(dynamic_array), rows, cols);
      delete[] dynamic_array;
    }
    return 0;
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
