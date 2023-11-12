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
  int readArray()
  {
    int val = 0;
    if (input.is_open() && input)
    {
      input >> val;
    }
    else if (!input.is_open())
    {
      throw std::invalid_argument("Can not open input.txt");
    }
    if (!input)
    {
      throw std::logic_error("Input error");
    }
    return val;
  }
  int MaximalSum(int inputArr[100][100], int line, int column)
  {
    const int ssize = 100;
    int max1 = 0;
    int max2 = 0;
    int sum1[ssize] = { 0 };
    int sum2[ssize] = { 0 };
    for (int i = 0; i < line; i++)
      for (int j = 0; j < column; j++)
      {
        if (i > j)
        {
          sum1[i - j] += inputArr[i][j];
        }
        if (i < j)
        {
          sum2[j - i] += inputArr[i][j];
        }
      }
    for (int i = 0; i < line; i++)
    {
      if (max1 < sum1[i])
      {
        max1 = sum1[i];
      }
      if (max2 < sum2[i])
      {
        max2 = sum2[i];
      }
    }
    return std::max(max1, max2);
  }
}
