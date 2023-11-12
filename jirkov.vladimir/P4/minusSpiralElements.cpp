#include <iostream>
#include "minusSpiralElements.hpp"
void minusSpiralElements(int **matrix, int m, int n)
{
  int value = 1;
  int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;
  while (row_start <= row_end && col_start <= col_end)
  {
    for (int i = col_start; i <= col_end; i++)
    {
      matrix[row_end][i] -= value;
      value++;
    }
    row_end--;

    for (int i = row_end; i >= row_start; i--)
    {
      matrix[i][col_end] -= value;
      value++;
    }
    col_end--;

    if (row_start <= row_end)
    {
      for (int i = col_end; i >= col_start; i--)
      {
        matrix[row_start][i] -= value;
        value++;
      }
      row_start++;
    }
    if (col_start <= col_end)
    {
      for (int i = row_start; i <= row_end; i++)
      {
        matrix[i][col_start] -= value;
        value++;
      }
      col_start++;
    }
  }
}

void printMatrix(int **matrix, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
