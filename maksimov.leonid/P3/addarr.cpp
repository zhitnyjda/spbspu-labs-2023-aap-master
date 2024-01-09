#include "addarr.hpp"

char* addarr(std::istream& in, char* arr, size_t& size_arr)
{
  char* newArr = new char[(size_arr * 2) + 1]{};
  for (size_t i = 0; i < size_arr; i++)
  {
    newArr[i] = arr[i];
  }
  size_t count = size_arr;
  char temp = 0;
  in >> std::noskipws;
  while ((in >> temp) && count < (size_arr * 2) - 1)
  {
    if (temp == '\n')
    {
      break;
    }
    newArr[count++] = temp;
  }
  if (temp == 0 && size_arr == 10)
  {
    delete[] arr;
    delete[] newArr;
    throw std::exception();
  }
  in >> std::skipws;
  newArr[count] = temp;
  delete[] arr;
  arr = newArr;
  size_arr *= 2;
  return arr;
}
