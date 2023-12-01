#include "fun.hpp"
#include <iostream>
char * seryj::changeArray(char* curr_arr, int size)
{
  char * values = new char[size*2];
  if(!values)
    throw std::logic_error("Not enough space for array");
  for (int i = 0; i <= size; i++)
  {
    values[i] = curr_arr[i];
  }
  delete[] curr_arr;
  return values;
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
