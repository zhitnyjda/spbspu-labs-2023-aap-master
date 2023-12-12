#include "buildWithoutInt.hpp"
#include <cctype>

int redko::buildWithoutInt(char * dest, char * src, int size)
{
  int s = 0;
  for (int i = 0; i < size; i++)
  {
    if (isdigit(src[i]) == 0)
    {
      dest[s++] = src[i];
    }
  }
  return s;
}
