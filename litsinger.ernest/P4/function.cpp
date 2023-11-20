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
      throw (std::invalid_argument("Too many arguments\n"));
    }
    if (args < 4)
    {
      throw (std::invalid_argument("Not enough arguments\n"));
    }
    input.open(argv[2]);
    output.open(argv[3]);
    int n = std::strtoll(argv[1], nullptr, 10);
    if (n < 1 || n>2)
    {
      throw(std::invalid_argument("First parameter is out of range\n"));
    }
    return n;
  }
  int MaximalSum(const int * arr, size_t rows, size_t cols)
  {
    int maxSum = arr[0];
    for (size_t i = 1; i < rows; ++i)
    {
      int sum = 0;
      for (size_t j = 0; j <= i; ++j)
      {
        sum += arr[i * cols + j] + arr[j * cols + i];
      }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
    }
    for (size_t j = 1; j < cols; ++j)
    {
      int sum = 0;
      for (size_t i = 0; i < rows && i + j < cols; ++i)
      {
        sum += arr[i * cols + i + j] + arr[(i + j) * cols + i];
      }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
    }
    return maxSum;
  }
}
