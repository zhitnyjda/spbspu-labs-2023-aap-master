#include "matrix.hpp"
#include <stdexcept>

int shagieva::matrixReader(std::ifstream & input, int * values, const int numberOfValues)
{
  for (int read = 0; read < numberOfValues; read++)
  {
    if (!(input >> values[i]))
    {
      return read;
    }

    if (!input)
    {
      throw std::invalid_argument("Something is wrong with values of matrix.\n");
    }
  }

  return read;
}

int shagieva::findMaxColumn()
{
  int maxColumn = 0;
  int maxSeq = 0;
  int maxCurrentSeq = 0;

  for (int column = 0; column < numberOfColumns; column++)
  {
    int currentSeq = 0;

    for (int row = 1; row < numberOfRows; row++)
    {
      int currentNumber = values[row * numberOfColumns + column];
      int previousNumber = values[(row - 1) * numberOfColumns + column];

      if (currentNumber == previousNumber)
      {
        currentSeq++;
      }

      if (currentSeq > maxCurrentSeq)
      {
        maxCurrentSeq = currentSeq;
      }
    }

    if (maxCurrentSeq > maxSeq)
    {
      maxSeq = maxCurrentSeq;
      maxColumn = column + 1;
    }
  }
  return maxColumn;
}
