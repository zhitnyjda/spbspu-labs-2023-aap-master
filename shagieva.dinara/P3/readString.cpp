#include "readString.hpp"
#include <stdexcept>
#include "increaseString.hpp"

char * shagieva::readString(std::istream & input, size_t & read)
{
  char * inputStr = new char[10]{};
  size_t add = 10;
  char cur = 0;

  input >> std::noskipws;

  input >> cur;
  if (cur == '\n' || cur == '\0')
  {
    delete[] inputStr;
    throw std::invalid_argument("Empty line entered.\n");
  }

  do
  {
    inputStr[read++] = cur;

    if (read % add == 0)
    {
      inputStr = shagieva::increaseString(inputStr, read, add);
    }
    input >> cur;
  }
  while (input && cur != '\n' && cur != '\0');

  input >> std::skipws;

  return inputStr;
}
