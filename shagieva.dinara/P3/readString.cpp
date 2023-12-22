#include "readString.hpp"
#include <stdexcept>
#include <iostream>


char * shagieva::readString(size_t & read)
{
  char * inputStr = new char[10]{};
  size_t add = 10;
  char cur = 0;

  std::cin >> std::noskipws;
  do
  {
    std::cin >> cur;
    if (read == 0 && cur == '\n')
    {
      delete[] inputStr;
      throw std::invalid_argument("Empty line entered.\n");
    }
    inputStr[read++] = cur;
    if (read % add == 0)
    {
      char * newInputStr = new char[read + add];
      for (size_t i = 0; i < read; i++)
      {
        newInputStr[i] = inputStr[i];
      }
      delete [] inputStr;
      inputStr = newInputStr;
    }
  }
  while (cur != '\n');
  std::cin >> std::skipws;

  return inputStr;
}
