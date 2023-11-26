#include "uppLow.hpp"
#include <cstddef>
#include <cctype>
#include <iostream>

void shagieva::uppLow(char * input, char * changedStr, size_t read)
{
  char cur = 0;
  for (size_t i = 0; i < read; i++)
  {
    cur = input[i];
    if (isupper(cur))
    {
      changedStr[i] = tolower(cur);
    }
    else
    {
      changedStr[i] = cur;
    }
  }
}
