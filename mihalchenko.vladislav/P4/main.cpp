#include <iostream>
#include <fstream>
#include <cmath>
#include <ctype.h>
#include "matrix.hpp"
#include "inputArray.hpp"
#include "outputArray.hpp"

int main(int argc, char** argv)
{
  using namespace mihalchenko;
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (isdigit(*argv[1]) != true)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if ((*argv[1] != '1') && (*argv[1] != '2'))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  int num;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;

  input >> rows >> cols;
  {
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }

  if ((rows == 0) && (cols == 0))
  {
    std::ofstream output(argv[3]);
    output << rows << " " << cols << " ";
    return 0;
  }

  if (((rows == 0) || (cols == 0)) && (!((rows == 0) && (cols == 0))))
  {
    std::cout << "Cannot be an element\n";
    return 1;
  }

  if (num == 1)
  {
    if (rows * cols > 10000)
    {
      std::cerr << "The number of matrix elements exceeds 10000";
      return 1;
    }

    float masInput[rows * cols];
    size_t result = inputArray(input, masInput, rows * cols);

    if (!input)
    {
      std::cerr << "Read " << result << " elements...\n";
      return 2;
    }
    outputDinArray(argv[3], masInput, rows, cols);
    return 0;
  }

  if (num == 2)
  {
    float* m1 = nullptr;
    try
    {
      m1 = createMatrix(rows, cols);
    }
    catch(...)
    {
      freeMatrix(m1);
      return 2;
    }

    for (size_t i = 0; i < rows * cols; i++)
    {
      if (!(input >> m1[i]))
      {
        return i;
      }
    }
    outputDinArray(argv[3], m1, rows, cols);
    freeMatrix(m1);
    return 0;
  }
  else
  {
    return 2;
  }
}
