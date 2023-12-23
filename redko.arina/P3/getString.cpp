#include "getString.hpp"
#include <iostream>

char * redko::getString(char *& dest, int & len, const int add)
{
  char c = ' ';
  std::cin >> std::noskipws;
  while (std::cin >> c && c != '\n')
  {
    dest[len++] = c;
    if (len % add == 0)
    {
      char* destNew = new char[len + add];
      if (!destNew)
      {
        return nullptr;
      }
      for (int i = 0; i < len; i++)
      {
        destNew[i] = dest[i];
      }
      delete[] dest;
      dest = destNew;
    }
  }
  dest[len] = '\0';
  std::cin >> std::skipws;
  return dest;
}
