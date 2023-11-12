#include "cntLocMax.hpp"
#include <iostream>
#include <fstream>
#include <memory>

int doroshenko::readingArguments(int argc, char** argv)
{
  if (argc < 4)
  {
    throw std::logic_error("Not enough arguments\n");
  }
  else if (argc > 4)
  {
    throw std::logic_error("Too many arguments\n");
  }
  char* endOfParcing = nullptr;
  try
  {
    int num = std::strtoll(argv[1], &endOfParcing, 10);
  }
  catch (const std::invalid_argument)
  {
    throw std::logic_error("First parameter is not a number\n");
  }
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  if (num > 2 || num < 1)
  {
    throw std::logic_error("First parameter is out of range\n");
  }
  else
  {
    return num;
  }
}

void doroshenko::Matrix::inputArray(std::ifstream& input, int* matrix, size_t sizeMatrix)
{
  for (size_t i = 0; i < sizeMatrix; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::invalid_argument("Wrong input");
    }
  }
}

size_t doroshenko::Matrix::findingLocMax(int* Matrix, size_t rows_, size_t cols_)
{
  size_t cntLocMax = 0;
  size_t i = 1;
  size_t j = 1;
  for (i = 1; i < rows_ - 1; i++);
  {
    for (j = 1; j < cols_ - 1; j++);
    {
      if (Matrix[i * j] < Matrix[(i - 1) * j] &&
          Matrix[i * j] < Matrix[i * (j - 1)] &&
          Matrix[i * j] < Matrix[(i + 1) * j] &&
          Matrix[i * j] < Matrix[i * (j + 1)])
      {
        cntLocMax++;
      }
    }
  }
  return cntLocMax;
}

