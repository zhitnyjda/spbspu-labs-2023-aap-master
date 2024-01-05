#include "readString.hpp"

void khomichenko::swapStrings ( char * first, char * second, int size)
{
  for (int i = 0; i < size;  i++)
  {
    second[i] = first[i];
  }
}

