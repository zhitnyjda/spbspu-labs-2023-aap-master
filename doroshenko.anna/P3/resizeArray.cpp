#include "resizeArray.hpp"

char* doroshenko::resizeArray(char* array, size_t size, size_t newSize)
{
  char* newArray = new char[newSize + 1];
  for (size_t i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
  for (size_t j = size; j < newSize; j++)
  {
    newArray[j] = '0';
  }
  delete[] array;
  return newArray;
}
