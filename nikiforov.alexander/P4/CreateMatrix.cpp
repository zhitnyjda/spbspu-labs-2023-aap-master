#include <iostream>
#include <iomanip>
#include "CreateMatrix.hpp"

nikiforov::Matrix::Matrix() {
  count = 1;
  elemetscount = 0;
}

size_t nikiforov::Matrix::inputMatrix(std::ifstream& in, int* ArrMatrix, size_t lenth)
{
  for (size_t i = 0; i < lenth; i++) {
    if (!(in >> ArrMatrix[i]))
    {
      throw std::invalid_argument("Invalid argument");
    }
    elemetscount++;
  }
  return elemetscount;
}

void nikiforov::Matrix::spiralMatrix(std::ofstream& out, int* ArrMatrix, size_t rows, size_t cols) {
  if (rows != cols) {
    std::cerr << "Error: Matrix is not square.";
    exit(0);
  }
  size_t p = rows / 2;
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
  out << rows << " ";
  out << cols << " ";
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      out << std::setw(4) << ArrMatrix[i * rows + j];
    }
  }
  delete[] ArrMatrix;
}
