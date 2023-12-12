#include "decreaseSpiralElements.hpp"
#include <stdexcept>

void jirkov::decreaseSpiralElements(int *matrix, int rows, int cols)
{
  int value = 1;
  int rowstart = 0;
  int rowend = rows - 1;
  int colstart = 0;
  int colend = cols - 1;

  while (rowstart <= rowend && colstart <= colend)
  {
    for (int i = rowend; i >= rowstart; i--)
    {
      matrix[i * cols + colstart] -= value;
      value++;
    }
    colstart++;

    for (int i = colstart; i <= colend; i++)
    {
      matrix[rowstart * cols + i] -= value;
      value++;
    }
    rowstart++;

    if (rowstart <= rowend)
    {
      for (int i = rowstart; i <= rowend; i++)
      {
        matrix[i * cols + colend] -= value;
        value++;
      }
      colend--;
    }

    if (colstart <= colend)
    {
      for (int i = colend; i >= colstart; i--)
      {
        matrix[rowend * cols + i] -= value;
        value++;
      }
      rowend--;
    }
  }
}
