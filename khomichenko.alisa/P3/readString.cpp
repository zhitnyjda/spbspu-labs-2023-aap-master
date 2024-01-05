#include "readString.hpp"

int khomichenko::readString(char * firstInput, char lit, const int read)
{
  if (lit=='\n')
  {
    firstInput[read] = 0;
    return 0;
  }
  firstInput[read] = lit;
  return 1;
}

