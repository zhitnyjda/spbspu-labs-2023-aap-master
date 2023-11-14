#include <iostream>
#include <fstream>
#include <limits>

size_t count_saddle(size_t rows, size_t cols, size_t * matrix);
int main(int argc, char ** argv)
{
  if(argc != 4)
  {
    std::cerr << "The number of paramets entered is not 3!\n";
    return 1;
  }
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  if(num == 0 && endOfParcing == argv[1])
  {
    std::cerr << "It is not a number!\n";
    return 1;
  }
  else if(num != 1 || num != 2)
  {
    std::cerr << "Need 1 or 2!\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if(!input)
    {
      std::cerr << "We can't read rows, cols\n";
      return 2;
    }
    size_t size = rows * cols;
    size_t realSize = 0;
    size_t element = 0;
    while(input >> element)
    {
      realSize += 1;
    }
    if(size != realSize)
    {
      std::cerr << "The specified matrix size does not correspond to reality!\n";
      return 2;
    }
  }
  if(num == 1)
  {
    std::ifstream input(argv[2]);
    size_t matrix[rows * cols] = {};
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * cols + j];
      }
    }
    std::ofstream output(argv[3]);
    output << count_saddle(rows, cols, matrix);
    return 0;
  }
  {
    std::ifstream input(argv[2]);
    size_t * matrix = new size_t[rows * cols];
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * cols + j];
      }
    }
    std::ofstream output(argv[3]);
    output << count_saddle(rows, cols, matrix);
    delete[] matrix;
    return 0;
  }
}
size_t count_saddle(size_t rows, size_t cols, size_t * matrix)
{
  size_t count = 0;
  size_t minrows = std::numeric_limits< size_t >::max();
  size_t maxcols = std::numeric_limits< size_t >::min();
  size_t coordinateMinRowsj = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if(matrix[i * cols + j] <= minrows)
      {
        minrows = matrix[i * cols + j];
        coordinateMinRowsi = i;
      }
    }
    for (size_t q = 0; q < rows; ++q)
    {
      if(matrix[q * cols + coordinateMinRowsj] >= maxcols)
      {
        maxcols = matrix[i * cols + coordinateMinRowsj];
      }
    }
    if (minrows == maxcols)
    {
      count += 1;
    }
  }
  return count;
}
