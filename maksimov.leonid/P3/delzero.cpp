#include "delzero.hpp"
#include <iostream>

char* delzero(char* arr, size_t& sizeArr)
{
  size_t count = 0;
  for (size_t i = 0; i < sizeArr; i++)
  {
    if (arr[i] == '\0')
    {
      count++;
    }
  }
  char* newArr = new char[(sizeArr - count) + 1]{};
  size_t counter = 0;
  for (size_t i = 0; i < sizeArr; i++)
  {
    if (arr[i] != '\0')
    {
      newArr[counter++] = arr[i];
    }
  }
  newArr[sizeArr - count] = '\0';
  delete[] arr;
  arr = newArr;
  sizeArr = (sizeArr - count) + 1;
  if (arr[0] == '\0' || arr[0] == '\n')
  {
    delete[] arr;
    throw std::exception();
  }
  return newArr;
}
