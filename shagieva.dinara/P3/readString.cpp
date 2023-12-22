#include "readString.hpp"
#include <stdexcept>
#include <iostream>

char * shagieva::readString(std::istream & input, size_t & read)
{
  char * inputStr = new char[10]{};
  size_t add = 10;
  char cur = 0;

  input >> std::noskipws;
  do
  {
    input >> cur;

    if (read == 0 && (cur == '\n' || cur == '\0'))
    {
      delete[] inputStr;
      throw std::invalid_argument("Empty line entered.\n");
    }

    inputStr[read++] = cur;

    if (read % add == 0)
    {
      char * newInputStr = new char[read + add]{};
      for (size_t i = 0; i < read; i++)
      {
        newInputStr[i] = inputStr[i];
      }
      delete [] inputStr;
      inputStr = newInputStr;
    }
  }
  while (input && cur != '\n');
  input >> std::skipws;

  return inputStr;
}
