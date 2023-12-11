#include "resizeArray.hpp"

char* doroshenko::resizeArray(char* array, size_t size, size_t newSize)
{
  char* newArray = new char[newSize + 1];
  size_t i;
  size_t j;
  for (i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
  for (j = size; j < newSize; j++)
  {
    newArray[j] = '0';
  }
  delete[] array;
  return newArray;
}
