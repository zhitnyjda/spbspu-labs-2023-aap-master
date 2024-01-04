#include <iostream>
#include <cstring>
#include <cstddef>
#include "findCommonChars.hpp"

int hohlova::findCommonChars(const char* s)
{
  int inputString[10] = { 0 };
  for (size_t i = 0; i < strlen(s) - 1; i++)
  {
    if (s[i] == s[i + 1])
    {
      return 1;
    }
  }
  return 0;
}

