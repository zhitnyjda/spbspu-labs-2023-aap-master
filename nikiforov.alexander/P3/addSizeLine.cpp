#include "addSizeLine.hpp"

char* nikiforov::AddElem(char* arr, size_t size, size_t lenth)
{
  char* newArr = new char[lenth + size];

  for (size_t i = 0; i < lenth; i++)
  {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
  return arr;
}
