#include "locMax.hpp"

using namespace sadofeva;
int locMax(int * values, size_t rows, size_t cols)
{
  int count = 0;
  for (int i = 0; i < rows;i++)
  {
    for (int j = 0; j < cols;j++)
    {
      if (*(values + (i * j)) > *(values + (i * j + 1)) && *(values + (i * j -1)) < *(values + (i * j)))
      {
        count++;
      }
    }
  }
  return count;
}
