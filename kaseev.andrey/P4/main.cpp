#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char **argv)
{
  if (argc > 4)
  {
    throw (std::invalid_argument("There are more arguments than should be!"));
  }
  if (argc < 4)
  {
    throw (std::invalid_argument("There are not enough arguments!"));
  }
  int num = std::strtoll(argv[1], nullptr, 10);
  if (num != 1 && num != 2)
  {
    throw (std::invalid_argument("Invalid argument!"));
  }
  std::ifstream cin(argv[2]);
  int m = 0, n = 0;
  if (!(cin >> n >> m))
  {
    std::cerr << "invalid input" << "\n";
    return 1;
  }
  if (m <= 0 || n <= 0)
  {
    std::cerr << "Invalid matrix dimensions." << "\n";
    return 1;
  }
  std::ofstream cout(argv[3]);
  if (num == 1)
  {
    int *matrix = nullptr;
    MatrixStuff::readMatrix(cin, matrix, n, m);
    size_t count = MatrixStuff::NumberOfDiagonals(matrix);
    if (cout.is_open())
    {
      MatrixStuff::writeResult(cout, count);
      cout.close();
    } else
    {
      std::cerr << "Unable to open the output file." << "\n";
    }
  } else
  {
    try
    {
      int *matrix = new int[n * m];
      size_t count = MatrixStuff::NumberOfDiagonals(matrix);
      if (cout.is_open())
      {
        MatrixStuff::writeResult(cout, count);
        cout.close();
      } else
      {
        std::cerr << "Unable to open the output file." << std::endl;
      }
      delete[] matrix;
    }
    catch (std::exception &err)
    {
      std::cerr << err.what() << "\n";
    }
  }
}
