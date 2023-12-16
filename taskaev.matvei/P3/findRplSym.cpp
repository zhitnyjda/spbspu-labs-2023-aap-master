#include "findRplSym.hpp"

char * taskaev::findRplSym(char * string)
{
  for (int i = 0; string[i] != '\0' ; i++)
  {
    string[i] = (string[i] == 'c' ? 'b' : string[i]);
  }
  return string;
}
