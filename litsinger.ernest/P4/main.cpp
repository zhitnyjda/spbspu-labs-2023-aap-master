#include <iostream>
#include <fstream>
#include "function.hpp"

using namespace litsinger;
int main(int args, const char* argv[])
{
  try
  {
    int maximum = 0;
    int task = litsinger::fillArguments(args, argv);
    Matrix matrix;
    matrix.line = readArray();
    matrix.column = readArray();
    const int coll = matrix.column;
    if (task == 1)
    {
      int static_array[100][100] = {0};
      for (int i = 0; i < matrix.line; i++)
        for (int j = 0; j < matrix.column; j++)
        {
          static_array[i][j] = readArray();
        }
      matrix.fillArray();
      maximum = MaximalSum(static_array, matrix.line, matrix.column);
    }
    else if (task == 2)
    {
      int **dynamic_array = new int* [matrix.line];
      for (int i = 0; i < matrix.line; i++)
      {
        dynamic_array[i] = new int[matrix.column];
      }
      for (int i = 0; i < matrix.line; i++)
        for (int j = 0; j < matrix.column; j++)
        {
          dynamic_array[i][j] = readArray();
        }
      try
      {
        matrix.fillArray();
        maximum = MaximalSumma(** dynamic_array, matrix.line, matrix.column);
        delete[] dynamic_array;
      }
      catch (std::logic_error const& e)
      {
        std::cerr << e.what();
        delete[] dynamic_array;
        return 2;
      }
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (std::logic_error& e)
  {
    std::cerr << e.what();
    return 2;
  }
}
