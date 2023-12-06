#include <iostream>
#include <fstream>
#include <cmath>
#include "outputArray.hpp"

void mihalchenko::outputDinArray(char* argv3, float* matrix, size_t rows, size_t cols)
{
  float* matrixNew = new float[rows * cols];

  int countNew = 0;
  int sum = 0;
  int iRows = static_cast<int>(rows);
  int iCols = static_cast<int>(cols);

  for (int m = 0; m < iRows; ++m)
  {
    for (int n = 0; n < iCols; ++n)
    {
      countNew = 0;
      sum = 0;
      for (int i = m - 1; i <= m + 1; ++i)
      {
        if ((i >= 0) and (i < iRows))
        {
          for (int j = n - 1; j <= n + 1; ++j)
          {
            if ((j >= 0) and (j < iCols))
            {
              if ((m == i) and (n == j))
              {
                continue;
              }
              else
              {
                countNew++;
                sum += matrix[i * cols + j];
              }
            }
          }
        }
      }
      if (countNew != 0)
      {
        matrixNew[m * cols + n] = float(sum) / countNew;
      }
    }
  }
  std::ofstream output(argv3);
  output << rows << " " << cols << " ";
  for (size_t i = 0; i < rows * cols; ++i)
  {
    //output << (float) round(matrixNew[i] * 10) / 10 << " ";
    // std::cout << matrixNew[i] << ' ';
    output << static_cast<float>(round(matrixNew[i] * 10)) / 10 << " ";
  }
}
