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
  for (size_t i = 0; i < sizeArr; i++)
  {
    if (newArr[i] == '\0')
    {
      counter++;
    }
    else
    {
      break;
    }
  }
  if (counter == sizeArr)
  {
    delete[] arr;
    delete[] newArr;
    throw std::exception();
  }
  return newArr;
}
