#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of elements.\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot parse a value.\n";
    return 3;
  }
  
  if (num > 2)
  {
    std::cout << "Number is out of range\n";
    return 2;
  }
  else if (num == 1)
  {
    size_t rows = 0, cols = 0;
    int matrix[10000];
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    for (int i = 0; i < rows * cols; i++)
    {
      input >> matrix[i];
    }
    if (!input)
    {
      std::cerr << "Cannot read a file.\n";
      return 2;
    }
    size_t MaxDiagonal = (matrix, cols, rows);
    {
      std::ofstream output(argv[3]);
      output << MaxDiagonal;
    }
    return 0;
  }

  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows, cols;
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }
  return 0;
}
