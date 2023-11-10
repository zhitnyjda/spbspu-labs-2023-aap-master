#include "structs.hpp"
#include <iostream>

miheev::Matrix::Matrix(size_t rows, size_t cols):
  nRows_(rows),
  nCols_(cols),
  matrix_(new int[rows*cols])
{}

void miheev::Matrix::initWithIfstream(std::ifstream& in)
{
  for (size_t i = 0; i < nRows_ * nCols_; ++i)
  {
    if (!(in >> matrix_[i]))
    {
      std::cerr << "Matrix is only partly initialized. Problems with ifstream\n";
      throw std::runtime_error("Some error occured while initing\n");
    }
  }
}

void miheev::Matrix::printSelf()
{
  std::cout << nRows_ << '\n' << nCols_ << '\n';
  for (size_t i = 0; i < nRows_; ++i)
  {
    for (size_t j = 0; j < nCols_; ++j)
    {
      std::cout << matrix_[i * nCols_ + j] << ' ';
    }
    std::cout << '\n';
  }
}
