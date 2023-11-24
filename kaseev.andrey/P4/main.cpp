#include <iostream>
#include <fstream>
#include "matrix.cpp"

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
      std::cerr << "Invalid argument!";
    }
    std::ifstream input(argv[2]);
    int m = 0, n = 0;
    if (!(input >> n >> m))
    {
      std::cerr << "invalid input" << "\n";
    }
    if (m <= 0 || n <= 0)
    {
      std::cerr << "Invalid matrix dimensions." << "\n";
    }
    try
    {
      std::ofstream output(argv[3]);
      if (num == 1)
      {
        int matrix[n * m];
        MatrixStuff::readMatrix(input, matrix, n, m);
        size_t count = MatrixStuff::NumberOfDiagonals(matrix, n, m);
        if (output.is_open())
        {
          MatrixStuff::writeResult(output, count);
          output.close();
        } else
        {
          std::cerr << "Unable to open the output file." << "\n";
        }
      } else
      {
        int *matrix = new int[n * m];
        MatrixStuff::readMatrix(input, matrix, n, m);
        size_t count = MatrixStuff::NumberOfDiagonals(matrix, n, m);
        delete[] matrix;
        if (output.is_open())
        {
          MatrixStuff::writeResult(output, count);
          output.close();
        } else
        {
          std::cerr << "Unable to open the output file." << std::endl;
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

