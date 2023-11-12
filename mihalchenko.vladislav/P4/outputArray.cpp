#include "outputArray.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

size_t writeArray::outputArray(char * argv3, int * matrix, size_t rows, size_t cols)
{
  float* matrixNew = new float[rows * cols];

  int countNew = 0;
  int sum = 0;

  for (int ii = 0; ii < rows; ++ii)
  {
    for (int jj{ 0 }; jj < cols; jj++)
    {
      countNew = 0;
      sum = 0;
      for (int i = ii - 1; i <= ii + 1; i++)
      {
        if ((i >= 0) and (i < rows))
        {
          for (int j = jj - 1; j <= jj + 1; j++)
          {
            if ((j >= 0) and (j < cols))
	    {
	      if ((ii == i) and (jj == j))
	      {
	        // int c = 7;
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
        matrixNew[ii * cols + jj] = float(sum) / countNew;
      }
    }
  }
  std::ofstream output(argv3);
  output << rows << " " << cols << " ";
  for (size_t i = 0; i < rows * cols; ++i)
  {
    output << (float) round(matrixNew[i] * 10) / 10 << " ";
  }
  return 0;
}
