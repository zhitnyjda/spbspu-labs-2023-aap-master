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
    int maxSum = std::numeric_limits<int>::min();
    for (int i = 0; i < cols; i++)
    {
      int sum = 0;
      for (int row = 0, column = i; row < rows && column < cols; row++, column++)
      {
	    if (row != column)
	    {
	      sum += arr[row * cols + column];
	    }
      }
      maxSum = std::max(maxSum, sum);
    }
    for (int i = 1; i < rows; i++)
    {
      int sum = 0;
      for (int row = i, column = 0; row < rows && column < cols; row++, column++)
      {
	    if (row != column)
	    {
          sum += arr[row * cols + column];
	    }
      }
      maxSum = std::max(maxSum, sum);
    }
    return maxSum;    
  }
}
