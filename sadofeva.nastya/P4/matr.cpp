#include "matr.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
namespace sadofeva
{
  Matrix::Matrix(){}
  int Matrix::fl_ar(ystd::ifstream& file, int *& values)
  {
    int count = 0;
    while (file.good())
    {
      file >> *(values + count);
      count++;
      return count;
    }
  }
  int Matrix::locMax(int* values, int rows, int cols)
  {
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 1; j < cols; j++)
      {
        if (*(values + (i * j)) > *(values + (i * j + 1)) && *(values + (i * j - 1)) < *(values + (i * j)))
        {
          count++;
        }
      }
    }
    return count;
  }
}
