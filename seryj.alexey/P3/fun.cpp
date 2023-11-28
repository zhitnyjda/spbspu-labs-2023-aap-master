#include "fun.hpp"
#include <iostream>
char * seryj::changeArray(char * curr_arr, int size)
{
  char * pointer = new char[size*2];
  if(!pointer)
    throw std::logic_error("Not enough space for array");
  for (int i = 0; i <= size; i++)
  {
    pointer[i] = curr_arr[i];
  }
  return pointer;
}
size_t seryj::streql(char* arr, int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
    {
      count += (arr[i] == arr[j]);
    }
  return count;
}
