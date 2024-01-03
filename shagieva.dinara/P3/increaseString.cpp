#include "increaseString.hpp"

char * shagieva::increaseString(char * inputStr, const size_t & read, const size_t & add)
{
  char * newInputStr = new char[read + add]{};
  for (size_t i = 0; i < read; i++)
  {
    newInputStr[i] = inputStr[i];
  }
  delete [] inputStr;
  return newInputStr;
}
