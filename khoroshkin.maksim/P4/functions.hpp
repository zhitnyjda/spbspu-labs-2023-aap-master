#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace khoroshkin
{
  class matrix
  {
  public:
    void inputArray(std::ifstream & in, int * matrix, size_t sizeMatrix);
    long long minSumOfParallelArray(int * matrix, int Rows, int Cols);
  private:
    int Rows;
    int Cols;
    int * matrix;
    size_t sizeMatrix;
  };
}

#endif
