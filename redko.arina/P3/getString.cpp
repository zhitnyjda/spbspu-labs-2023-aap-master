#include "getString.hpp"
#include <iostream>

char * redko::getString(char *& dest, int & len, const int add)
{
  //len = 0;
  char c;
  std::cin >> std::noskipws;
  do
  {
    std::cin >> c;
    dest[len++] = c;
    if (len % add == 0)
    {
      char* destNew = new char[len + add];
      if (!destNew)
      {
        delete[] dest;
        return nullptr;
      }
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
//  return len;
  return dest;
}
