#include "decreaseSpiralElements.hpp"
#include <stdexcept>

void jirkov::decreaseSpiralElements(int *matrix, int rows, int cols)
{
  int num = -1;
  int r1 = 0;
  int r2 = rows - 1;
  int c1 = 0;
  int c2 = cols - 1;

  while (r1 <= r2 && c1 <= c2)
  {
    for (int c = c1; c <= c2; c++)
    {
      matrix[r2 * cols + c] = num;
      num--;
    }
    for (int r = r2 - 1; r >= r1; r--)
    {
      matrix[r * cols + c2] = num;
      num--;
    }
    if (r1 < r2 && c1 < c2)
    {
      for (int c = c2 - 1; c > c1; c--)
      {
        matrix[r1 * cols + c] = num;
        num--;
      }
      for (int r = r1; r < r2; r++)
      {
        matrix[r * cols + c1] = num;
        num--;
      }
    }
    r1++;
    r2--;
    c1++;
    c2--;
  }
}
