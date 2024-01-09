#include "addarr.hpp"

char* addarr(std::istream& in, char* arr, size_t& size_arr, bool& endin)
{
  char* newArr = new char[(size_arr * 2) + 1]{};
  for (size_t i = 0; i < size_arr; i++)
  {
    newArr[i] = arr[i];
  }
  size_t count = size_arr;
  char temp = 0;
  in >> std::noskipws;
  while ((in >> newArr[count]) && count < (size_arr * 2) - 1)
  {
    if (newArr[count++] == '\0' || newArr[count++] == '\n')
    {
      endin = 0;
      break;
    }
  }
  in >> std::skipws;
  newArr[count] = temp;
  delete[] arr;
  arr = newArr;
  size_arr *= 2;
  return arr;
}
