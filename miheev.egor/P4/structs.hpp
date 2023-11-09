#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <cstddef>
#include <fstream>

namespace miheev
{
  class Matrix
  {
  private:
    std::size_t nRows_;
    std::size_t nCols_;
    int* matrix_;

  public:
    Matrix (std::size_t rows, std::size_t cols);
    void initWithIfstream(std::ifstream& in);
  };
}
#endif
