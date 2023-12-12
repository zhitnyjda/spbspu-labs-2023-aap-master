#include <iostream>
#include <fstream>
#include <cstring>
#include "count_saddle.hpp"
#include "create_matrix.hpp"
using namespace kovshikov;

int main(int argc, char ** argv)
{
  if(argc != 4)
  {
    std::cerr << "The number of paramets entered is not 3!\n";
    return 1;
  }
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], std::addressof(endOfParcing), 10);
  int lenght = strlen(argv[1]);
  if(endOfParcing != argv[1] + lenght)
  {
    std::cerr << "It is not a number!\n";
    return 1;
  }
  else if(num != 1 && num != 2)
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
  Saddle saddle;
  size_t stat_matrix[rows * cols] = {};
  size_t * matrix = (num == 1)? stat_matrix : new size_t [rows * cols];
  createMatrix(matrix, argv[2]);
  std::ofstream output(argv[3]);
  output << saddle(rows, cols, matrix);
  if(num == 2)
  {
    delete [] matrix;
  }
  return 0;
}
