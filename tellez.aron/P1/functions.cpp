#include "functions.hpp"
#include <iostream>
#include <stdexcept>

int getSequence()
{
  int max_seq_count = 0;
  int current_seq_count = 0;
  int actual = -1;
  int value = 0;
  do
  {
    value = getNextValue();
    if (value <= actual)
    {
      current_seq_count = updateSequenceCounts(max_seq_count, current_seq_count);
    }
    else
    {
      current_seq_count = 0;
    }
    actual = value;
    max_seq_count = std::max(max_seq_count, current_seq_count);
  }
  while (value != 0);
  return max_seq_count;
}

int getNextValue()
{
  int value;
  std::cin >> value;
  if (!std::cin)
  {
    throw std::istream::failure("Not a valid input.");
  }
  return value;
}

int updateSequenceCounts(int max_seq_count, int current_seq_count)
{
  return std::max(max_seq_count, current_seq_count + 1);
}
