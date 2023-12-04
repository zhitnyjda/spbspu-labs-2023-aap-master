#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.hpp"
#include "inputArray.hpp"
#include "outputArray.hpp"

int main(int argc, char** argv)
{
  using namespace mihalchenko;
  if (argc != 4)
  {
    std::cerr << "Something wrong...\n";
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

  if (num == 1)
  {
    if (rows * cols > 10000)
    {
      std::cerr << "The number of matrix elements exceeds 10000";
    }

    float masInput[rows * cols];
    size_t result = inputArray(input, masInput, rows * cols);

    if (!input)
    {
      std::cerr << "Read " << result << "elements...\n";
      return 3;
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
      return 3;
    }

    for (size_t i = 0; i < rows * cols; ++i)
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
