#include "structs.hpp"

miheev::Matrix::Matrix(std::size_t rows, std::size_t cols):
  nRows_(rows),
  nCols_(cols),
  matrix_(new int[rows*cols])
{}

void miheev::Matrix::initWithIfstream(std::ifstream& in)
{
  for (std::size_t i = 0; i < nRows_ * nCols_; ++i)
  {
    if (!(in >> matrix_[i]))
    {
      throw std::runtime_error("Some error occured while initing");
    }
  }
}