#include "cntLocMax.hpp"
#include <iostream>

long long doroshenko::readingArguments(char** argv)
{
  char* endOfParcing = nullptr;
  long long num = std::strtoll(argv[1], &endOfParcing, 10);
  long long lenOfArg = strlen(argv[1]);
  if (endOfParcing != argv[1] + lenOfArg)
  {
    throw std::logic_error("First parameter is not a number\n");
  }
  else if (num > 2 || num < 1)
  {
    throw std::logic_error("First parameter is out of range\n");
  }
  else
  {
    return num;
  }
}

size_t doroshenko::inputArray(std::istream& input, int* Matrix, size_t sizeMatrix)
{
  for (size_t k = 0; k < sizeMatrix; k++)
  {
    input >> Matrix[k];
    if (!input)
    {
        return k;
    }
  }
  return sizeMatrix;
}

size_t doroshenko::findingLocMax(const int* Matrix, size_t rows_, size_t cols_)
{
  size_t cntLocMax = 0;
  for (size_t i = 1; i < rows_ - 1; i++)
  {
    for (size_t j = 1; j < cols_ - 1; j++)
    {
      if (Matrix[i * j] < Matrix[(i - 1) * j])
      {
        if (Matrix[i * j] < Matrix[i * (j - 1)])
        {
          if (Matrix[i * j] < Matrix[(i + 1) * j])
          {
            if (Matrix[i * j] < Matrix[i * (j + 1)])
            {
              cntLocMax++;
            }
          }
        }
      }
    }
  }
  return cntLocMax;
}
