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

void miheev::Matrix::printSelf() const
{
  std::cout << "rows = " << nRows_ << "\ncols = " << nCols_ << '\n';
  for (size_t i = 0; i < nRows_; ++i)
  {
    for (size_t j = 0; j < nCols_; ++j)
    {
      std::cout << matrix_[i * nCols_ + j] << ' ';
    }
    std::cout << '\n';
  }
}

void miheev::Matrix::increaseRectBorder(size_t xStart, size_t yStart, size_t width, size_t height, int increment)
{
  if (height == 1)
  {
    matrix_[nCols_ * yStart + xStart] += increment;
  }
  else
  {
    for (size_t j = xStart; j < xStart + width; ++j)
    {
      matrix_[nCols_ * yStart + j] += increment;
      matrix_[nCols_*(yStart + height - 1) + j] += increment;
    }
    for (size_t i = yStart + 1; i < yStart + height - 1; ++i)
    {
      matrix_[i * nCols_ + xStart] += increment;
      matrix_[i * nCols_ + xStart + width - 1] += increment;
    }
  }
 printSelf();
}

void miheev::Matrix::increasePeriphery()
{
  int increment = 1;
  size_t xs = 0;
  size_t ys = 0;
  size_t w = nCols_;
  size_t h = nRows_;
  while (ys + h <= nRows_ && xs + w <= nCols_ && h > 0 && w > 0)
  {
    // std::cout << "--------\nxs = " << xs << "\nys = " << ys << "\nw = " << w << "\nh = " << h << "\n sum xs + w = " << xs + w  + 1<< '\n';
    increaseRectBorder(xs, ys, w, h, increment);
    xs += 1;
    ys += 1;
    w = w > 2 ? w - 2 : 0;
    h = h > 2 ? h - 2 : 0;
    increment += 1;
  }
}
