#include "functions.hpp"
#include <iostream>
#include <cctype>
#include "matrix_methods.hpp"

size_t miheev::inputToArr(std::ifstream& in, int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    in >> arr[i];
    if (!in)
    {
      throw std::runtime_error("Error occured while trying to init arr. " + std::to_string(i) + " elements were read\n");
      return i;
    }
  }
  return size;
}

void miheev::printArrInline(const int* const arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

// bool isUInt(char* str, size_t size)
// {
//   for (size_t i = 0; i < size; i++)
//   {
//     if (!std::isdigit(str[i]))
//     {
//       return 0;
//     }
//   }
//   return 1;
// }

bool miheev::isUInt(char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (!std::isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}
