#include "matrix.hpp"
#include <stdexcept>

void shagieva::Matrix::read(std::ifstream & input)
{
  for (int i = 0; i < numberOfLines * numberOfColumns; i++)
  {
    input >> values[i];
    if (!input)
    {
      throw std::invalid_argument("Something is wrong with the matrix.\n");
    }
  }
}

int shagieva::Matrix::findMaxColumn()
{
  int maxColumn = 0;
  int maxSeq = 0;
  int maxCurrentSeq = 0;

  for (int column = 0; column < numberOfColumns; column++)
  {
    int currentSeq = 0;

    for (int line = 1; line < numberOfLines; line++)
    {
      int currentNumber = values[line * numberOfColumns + column];
      int previousNumber = values[(line - 1) * numberOfColumns + column];
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


