#include <iostream>
#include <fstream>
#include <cstring>
#include "funcs.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "you did not pass 4 arguments\n";
    return 1;
  }

  int number;
  try
  {
    for (size_t i=0; i < strlen(argv[1]); i++)
    {
      if (!(isdigit(argv[1][i])))
      {
        std::cerr << "the first argument should be int\n";
        return 1;
      }
    }
    number = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "the first argument should be int\n";
    return 1;
  }

  if (number == 1 || number == 2)
  {
    size_t rows = 0, cols = 0;

    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "input file cannot be opened\n";
      return 2;
    }

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "output file cannot be opened\n";
      return 2;
    }

    int statArray[10000] = {};
    int * matrix = (number == 1) ? statArray : new int[cols * rows];
    size_t counter = 0;
    counter = sobolevsky::sizeMatrix(input, matrix, (cols * rows), counter);
    if (counter != (cols*rows))
    {
      std::cerr << "matrix size and number of numbers are different\n";
      if (number == 2)
      {
        delete[] matrix;
      }
      return 2;
    }
    sobolevsky::isTrianglMatrix(output, matrix, rows, cols);
    if (number == 2)
    {
      delete[] matrix;
    }
    return 0;
  }
  else
  {
    std::cerr << "first argument should be either 1 or 2\n";
    return 1;
  }
}
