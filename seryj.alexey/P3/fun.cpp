#include "fun.hpp"
#include <iostream>
char * seryj::changeArray(char* old_values, int size)
{
  char * new_values = new char[size*2];
  for (int i = 0; i <= size; i++)
  {
    *(new_values+i) = *(old_values+i);
  }
  return new_values;
}
unsigned long long seryj::counterOfEqualPairs(char* values, int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
    {
      count += (values[i] == values[j]);
    }
  return count;
}
