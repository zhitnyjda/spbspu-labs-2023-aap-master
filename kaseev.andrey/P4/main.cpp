#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char **argv)
{
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("There are more arguments than should be!");
    }
    char *endptr;
    long long int num = std::strtol(argv[1], &endptr, 10);
    if (num != 1 && num != 2)
    {
      throw std::logic_error("Invalid argument!");
    }
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);
    int m = 0, n = 0;
    if (!(input >> n >> m))
    {
      throw std::logic_error("Invalid argument!");
    }
    if (m < 0 || n < 0)
    {
      throw std::logic_error("Invalid argument!");
    }
    else if (m == 0 && n == 0)
    {
      if (output.is_open())
      {
        MatrixStuff::writeResult(output, 0);
        output.close();
      }
    }
    try
    {
      if (num == 1)
      {
        int matrix[n * m];
        bool matrixCheck = false;
        matrixCheck = MatrixStuff::readMatrix(input, matrix, n, m);
        if (!matrixCheck)
        {
          throw std::logic_error("invalid input");
        }
        size_t count = MatrixStuff::NumberOfDiagonals(matrix, n, m);
        if (output.is_open())
        {
          MatrixStuff::writeResult(output, count);
          output.close();
        }
      } else
      {
        int *matrix = new int[n * m];
        bool matrixCheck = false;
        matrixCheck = MatrixStuff::readMatrix(input, matrix, n, m);
        if (!matrixCheck)
        {
          delete[] matrix;
          throw std::logic_error("invalid input");
        }
        size_t count = MatrixStuff::NumberOfDiagonals(matrix, n, m);
        delete[] matrix;
        if (output.is_open())
        {
          MatrixStuff::writeResult(output, count);
          output.close();
        }
      }
    }
    catch (std::exception &err)
    {
      std::cerr << err.what() << "\n";
      return 2;
    }
  }
  catch (std::exception &err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
}

