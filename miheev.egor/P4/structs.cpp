#include "structs.hpp"
#include <iostream>

miheev::Matrix::Matrix(size_t rows, size_t cols, long long mode):
  nRows_(rows),
  nCols_(cols)
{
  if (mode == 1)
  {
    int temp[10000] = {0};
    matrix_ = temp;
  }
  else if (mode == 2)
  {
    matrix_ = new int [rows*cols];
  }
}

void miheev::Matrix::initWithIfstream(std::ifstream& in)
{
  int current = 0;
  for (size_t i = 0; i < nRows_ * nCols_; i++)
  {
    in >> current;
    if (!in)
    {
      std::cerr << "Matrix is only partly initialized. Problems with ifstream\n";
      throw std::runtime_error("Some error occured while initing\n");
    }
    matrix_[i] = current;
  }
}

void miheev::Matrix::printSelf() const
{
  for (size_t i = 0; i < nRows_; i++)
  {
    for (size_t j = 0; j < nCols_; j++)
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
    for (size_t j = xStart; j < xStart + width; j++)
    {
      matrix_[nCols_ * yStart + j] += increment;
      matrix_[nCols_*(yStart + height - 1) + j] += increment;
    }
    for (size_t i = yStart + 1; i < yStart + height - 1; i++)
    {
      matrix_[i * nCols_ + xStart] += increment;
      matrix_[i * nCols_ + xStart + width - 1] += increment;
    }
  }
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

std::string miheev::Matrix::getMatrixInline() const
{
  std::string line = "";
  for (size_t i = 0; i < nRows_ * nCols_; i++)
  {
    line += std::to_string(matrix_[i]) + ' ';
  }
  return line;
}

size_t miheev::Matrix::getNRows() const
{
  return nRows_;
}

size_t miheev::Matrix::getNCols() const
{
  return nCols_;
}
