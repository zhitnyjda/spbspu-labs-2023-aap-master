#include "decreaseSpiralElements.hpp"
#include <iostream>
#include <stdexcept>
void jirkov::decreaseSpiralElements(int *matrix, size_t m, size_t n)
{
  size_t value = 1;
  size_t row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;
  while (row_start <= row_end && col_start <= col_end)
  {
    for (size_t i = row_end; i >= row_start; i--)
    {
      matrix[i * n + col_start] -= value;
      value++;
    }
    col_start++;

    for (size_t i = col_start; i <= col_end; i++)
    {
      matrix[row_start * m + i] -= value;
      value++;
    }
    row_start++;

    if (row_start <= row_end)
    {
      for (size_t i = row_start; i <= row_end; i++)
      {
        matrix[i * n + col_end] -= value;
        value++;
      }
      col_end--;
    }

    if (col_start <= col_end)
    {
      for (size_t i = col_end; i >= col_start; i--)
      {
        matrix[row_end * m + i] -= value;
        value++;
      }
      row_end--;
    }
  }
}


