#include "classes.hpp"

void zheleznyakov::Matrix::read(std::ifstream & input)
{
  for (int i = 0; i < columns * rows; i++)
  {
    input >> values[i];
    if (!input)
    {
      throw std::runtime_error("Error: The Matrix is broken: The provided dimensions of the matrix and its actual size do not correspond to each other.\n");
    }
  }
}
int zheleznyakov::Matrix::findMaxRow()
{
  int maxColumn = 0;
  int maxSequenceLength = 0;
  for (int col = 0; col < columns; col++)
  {
    int currentStreak = 0;
    int maxCurrentStreak = 0;
    for (int row = 1; row < rows; row++)
    {
      const int current = values[row * columns + col];
      const int previous = values[(row - 1) * columns + col];
      if (current == previous)
      {
        currentStreak++;
      }
      if (maxCurrentStreak < currentStreak)
      {
        maxCurrentStreak = currentStreak;
      }
    }
    if (maxSequenceLength < maxCurrentStreak)
    {
      maxSequenceLength = maxCurrentStreak;
      maxColumn = col + 1;
    }
  }
  return maxColumn;
}
