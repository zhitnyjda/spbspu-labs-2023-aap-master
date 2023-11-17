#include "function.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
namespace litsinger
{
  std::ifstream input;
  std::ofstream output;
  int fillArguments(int args, const char* argv[])
  {
    if (args > 4)
    {
      throw (std::invalid_argument("Too many arguments"));
    }
    if (args < 4)
    {
      throw (std::invalid_argument("Not enough arguments"));
    }
    input.open(argv[2]);
    output.open(argv[3]);
    int n = std::strtoll(argv[1], nullptr, 10);
    if (n < 1 || n>2)
    {
      throw(std::invalid_argument("First parameter is out of range"));
    }
    return n;
  }
  int MaximalSum(int * arr, size_t rows, size_t cols)
  {
    int maxSum = std::numeric_limits< int >::max();
    int max1 = 0;
    int max2 = 0;
    int Sum1[100] = { 0 };
    int Sum2[100] = { 0 };
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
      {
        if ((i < j))
        {
          Sum1[j - i] += arr[(i * cols) + j];
        }
        if ((i > j))
        {
          Sum2[i - j] += arr[(i * cols) + j];
        }
      }
    }
    for (size_t i = 0; i < (rows * cols); i++)
    {
      if (max1 < Sum1[i])
      {
        max1 = Sum1[i];
      }
      else if (max2 < Sum2[i])
      {
        max2 = Sum2[i];
      }
    }
    maxSum = std::max(max1, max2);
    return maxSum;
  }
}
