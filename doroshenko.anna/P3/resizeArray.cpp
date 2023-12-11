#include "resizeArray.hpp"

char* doroshenko::resizeArray(char* array, size_t size, size_t newSize)
{
  char* newArray = new char[newSize + 1];
  size_t i = 0;
  size_t j = size;
  for (i; i < size; i++)
  {
    newArray[i] = array[i];
  }
  for (j; j < newSize; j++)
  {
    newArray[j] = '0';
  }
  delete[] array;
  return newArray;
}
