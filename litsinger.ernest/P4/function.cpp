#include "function.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
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
  int MaximalSum(const int * arr, size_t lines, size_t column)
  {
    int maxSum = 0;
    for (size_t i = 1; i < lines; i++)
    {
      int sum = 0;
      for (size_t j = 0; j <= i; j++)
      {
        sum += arr[i * column + j] + arr[j * column + i];
      }
      if (sum > maxSum)
      {
          maxSum = sum;
      }
    }
    for (size_t j = 1; j < column; j++)
    {
      int sum = 0;
      for (size_t i = 0; i < lines && i + j < column; i++)
      {
        sum += arr[i * column + i + j] + arr[(i + j) * column + i];
      }
      if (sum > maxSum)
      {
          maxSum = sum;
      }
    }
    return maxSum;
  }
}
