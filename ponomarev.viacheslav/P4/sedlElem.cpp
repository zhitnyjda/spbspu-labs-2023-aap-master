#include "sedlElem.hpp"

int ponomarev::countingSed(int * matrix, int rows, int cols)
{
  int k = 0;
  for (int j = 0; j < rows; j++)
  {
    int a = 10000000;
    int b = 0;
    for (int i = (cols * j); i < (cols + cols * j); i++)
    {
      if (matrix[i] < a)
      {
        a = matrix[i];
      }
    }
    for (int i = (cols * j); i < (cols + cols * j); i++)
    {
      if (matrix[i] == a)
      {
        int c = i % cols;
        for (int p = c; p <= c + (cols * (rows - 1)); p += cols)
        {
          if (matrix[p] > b)
          {
            b = matrix[p];
          }
        }
      }
    }
    if (a == b)
    {
      k += 1;
    }
  }
  return k;
}
