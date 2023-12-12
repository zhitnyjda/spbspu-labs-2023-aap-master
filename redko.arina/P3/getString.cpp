#include "getString.hpp"
#include <iostream>

int redko::getString(char *& dest)
{
  int len = 0;
  const int add = 10;
  char c;
  std::cin >> std::noskipws;
  do
  {
    std::cin >> c;
    dest[len++] = c;
    if (len % add == 0)
    {
      char* destNew = new char[len + add];
      for (int i = 0; i < len; i++)
      {
        destNew[i] = dest[i];
      }
      delete[] dest;
      dest = destNew;
    }
  } while (c != '\n');
  dest[len-1] = '\0';
  std::cin >> std::skipws;
  return len;
}
