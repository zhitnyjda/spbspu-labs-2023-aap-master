#ifndef DECREASESPIRALELEMENTS_HPP   //decreaseSpiralElements
#define DECREASESPIRALELEMENTS_HPP
#include <cstddef>
#include <fstream>

namespace jirkov
{
  class matrix
  {
  public:
    void printMatrix(int **matrix, size_t m, size_t n);
    void decreaseSpiralElements(int **matrix, size_t m, size_t n);

  private:
    size_t value_;
    int row_start_;
    int row_end_;
    int col_start_;
    int col_end_;
  };
}
#endif
