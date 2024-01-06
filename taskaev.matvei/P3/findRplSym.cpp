#include "findRplSym.hpp"

char * taskaev::findRplSym(char * string, char simbolOld, char simbolNew)
{
  for (int i = 0; string[i] != '\0' ; i++)
  {
    string[i] = (string[i] == simbolOld ? simbolNew : string[i]);
  }
  return string;
}
