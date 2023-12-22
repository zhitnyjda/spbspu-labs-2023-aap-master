#include "readString.hpp"

void khomichenko::swapStrings ( char * first, char * second, int size, const char * type)
{
  for (int i = 0; i < size;  i++)
  {
    second[i]=first[i];
  }
}

char * khomichenko::createBiggerString (int * size, char * first)
{
  char * secondInput = new char [(*size)+(*size)]{};
  swapStrings(first, secondInput, (*size), "second");
  (*size)+=(*size);
  delete [] first;
  first = new char [(*size)]{};
  swapStrings(secondInput, first, (*size), "first");
  delete [] secondInput;
  return first;
}
