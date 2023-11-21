#include "decreaseSpiralElements.hpp"
#include <iostream>
#include <stdexcept>
void jirkov::matrix::printMatrix(int **matrix, size_t m, size_t n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
    std::cout << matrix[i][j] << " ";
    }
  std::cout << '\n';
  }
}
void jirkov::matrix::decreaseSpiralElements(int **matrix, size_t m, size_t n)
{
  size_t value_ = 1;
  int row_start_ = 0, row_end_ = m - 1, col_start_ = 0, col_end_ = n - 1;
  while (row_start_ <= row_end_ && col_start_ <= col_end_)
  {
    for (int i = row_end_; i >= row_start_; i--)
    {
      matrix[i][col_start_] -= value_;
      value_++;
    }
    col_start_++;

    for (int i = col_start_; i <= col_end_; i++)
    {
      matrix[row_start_][i] -= value_;
      value_++;
    }
    row_start_++;

    if (row_start_ <= row_end_)
    {
      for (int i = row_start_; i <= row_end_; i++)
      {
        matrix[i][col_end_] -= value_;
        value_++;
      }
      col_end_--;
    }

    if (col_start_ <= col_end_)
    {
      for (int i = col_end_; i >= col_start_; i--)
      {
        matrix[row_end_][i] -= value_;
        value_++;
      }
      row_end_--;
    }
  }
}
