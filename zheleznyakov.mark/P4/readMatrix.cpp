#include "functions.hpp"

int zheleznyakov::readMatrix(std::ifstream & input, int * matrix, int columns, int rows)
{
  int count = 0;
  for (int i = 0; i < columns * rows; i++)
  {
    input >> matrix[i];
    count++;
    if (!input)
    {
      throw std::runtime_error("Error: The Matrix is broken.\n");
    }
  }
  return count;
}
