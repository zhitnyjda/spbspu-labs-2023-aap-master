#include "Func.hpp"

using namespace nikiforov;
void nikiforov::Str::AddElem(char*& arr, size_t& size, size_t& lenth)
{
  if (lenth == size)
  {
    char* newArr = new char[lenth + 10];

    for (size_t i = 0; i < lenth; i++)
    {
      newArr[i] = arr[i];
    }
    size += 10;
    delete[] arr;
    arr = newArr;
  }
}

int nikiforov::Str::result(char* str1, char* str2, size_t len1, size_t len2) {
  for (size_t i = 0; i < len1; i++)
  {
    for (size_t j = 0; j < len2; j++)
    {
      if (str1[i] == str2[j] && str1[i] != ' ')
      {
        return 1;
        break;
      }
    }
  }
  return 0;
}
