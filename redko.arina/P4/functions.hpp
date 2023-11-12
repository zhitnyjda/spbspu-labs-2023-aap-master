#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>
namespace redko
{
  class matrix
  {
  public:
    void inputArray(std::ifstream & in, int * matrix, size_t matrixSize);
    int countCols(int * matrix, int rows, int cols);
  private:
    int rows;
    int cols;
    int * matrix;
    size_t matrixSize;
  };
}

#endif
