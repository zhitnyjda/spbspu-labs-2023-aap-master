#include <iostream>
#include "CreateMatrix.hpp"

nikiforov::Matrix::Matrix() {
  count = 1;
}

void nikiforov::Matrix::inputMatrix(std::ifstream& in, int* ArrMatrix, size_t cap)
{
  for (size_t i = 0; i < cap; i++) {
    if (!(in >> ArrMatrix[i]))
    {
      throw std::invalid_argument("Invalid argument");
    }
  }
}

void nikiforov::Matrix::spiralMatrix(int* ArrMatrix, size_t rows, size_t cols) {
  if (rows != cols) {
    std::cerr << "Error: Matrix is not square.";
    exit(0);
  }
  int p = rows / 2;
  size_t c = cols;
  size_t r = rows;
  for (size_t k = 1; k <= p; k++)
  {
    for (size_t j = k - 1; j < cols - k + 1; j++)
    {
      ArrMatrix[(c - 1) * rows + j] = ArrMatrix[(c - 1) * rows + j] + count;
      count++;
    }
    for (size_t j = r - k; j >= k; j--)
    {
      ArrMatrix[(j - 1) * rows + (c - 1)] = ArrMatrix[(j - 1) * rows + (c - 1)] + count;
      count++;
    }
    for (size_t j = cols - k - 1; j >= k; j--)
    {
      ArrMatrix[(k - 1) * rows + j] = ArrMatrix[(k - 1) * rows + j] + count;
      count++;
    }
    for (size_t j = k - 1; j < c - 1; j++)
    {
      ArrMatrix[j * rows + (cols - c)] = ArrMatrix[j * rows + (cols - c)] + count;
      count++;
    }
    if (rows % 2 == 1) {
      ArrMatrix[p * rows + p] = rows * cols;
    }
    c -= 1;
  }
}
