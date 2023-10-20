#include <iostream>
#include <stdexcept>
#include "getSequence.hpp"

int getSequence()
{
  int max_seq_count = 0;
  int current_seq_count = 0;
  int actual = -1;
  int value;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      throw std::istream::failure("Not a valid input.");
    }
    if (value <= actual)
    {
      current_seq_count = current_seq_count + 1;
      max_seq_count = std::max(max_seq_count, current_seq_count);
    }
    else
    {
      current_seq_count = 0;
    }
    actual = value;
  }
  while (value != 0);
  return max_seq_count;
}
