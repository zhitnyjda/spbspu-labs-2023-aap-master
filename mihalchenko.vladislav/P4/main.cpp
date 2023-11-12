#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "inputArray.hpp"
#include "outputArray.hpp"
#include <string>
#include <cmath>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong...\n";
    return 1;
  }

  int num;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

  std::ifstream input(argv[2]);

  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  {
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }

  if (num == 1)
  {
    if (num * cols > 10000)
    {
      std::cerr << "The number of matrix elements exceeds 10000";
    }

    int * matrix = new int[rows * cols];
    size_t result = readArray::inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Read " << result << "elements...\n";
      delete [] matrix;
      return 3;
    }
    writeArray::outputArray(argv[3], matrix, rows, cols);
    return 0;
  }
  if (num == 2)
  {
    int countNew = 0;
    int sum = 0;
    int ** m1 = nullptr;
    int ** m2 = nullptr;
    try
    {
      m1 = matrixLife::createMatrix(rows, cols);
      m2 = matrixLife::createMatrix(rows, cols);
    }
    catch(...)
    {
      //delete [] matrix;
      matrixLife::freeMatrix(m1, rows, cols);
      matrixLife::freeMatrix(m2, rows, cols);
      return 3;
    }
    for (int i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(input >> m1[i][j]))
        {
          return i;
        }
      }
    }
    std::ofstream output(argv[3]);
    output << rows << " " << cols << " ";
    for (int ii = 0; ii < rows; ++ii)
    {
      for(int jj {0}; jj < cols; jj++)
      {
        countNew = 0;
        sum = 0;
        for (int i = ii - 1; i <= ii + 1; i++)
        {
          if ((i >= 0) and (i < rows))
          {
            for(int j = jj - 1; j <= jj +1; j++)
            {
              if ((j >= 0) and (j < cols))
              {
                if ((ii == i) and (jj == j))
                {
                  //std::cout << std::endl;
                }
                else
                {
                  countNew ++;
                  sum += m1[i][j];
                }
              }
            }
          }
        }
        if (countNew != 0)
        {
          float rezult = float(sum) / countNew;
          m2[ii][jj] = rezult;
          output << (float) round(rezult * 10) / 10 << " ";
        }
      }
    }
    matrixLife::freeMatrix(m1, rows, cols);
    matrixLife::freeMatrix(m2, rows, cols);
    return 0;
  }
  else
    return 2;
}
