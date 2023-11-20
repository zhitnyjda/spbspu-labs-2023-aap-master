#include "functions.hpp"
#include <iostream>

void miheev::inputToArr(std::ifstream& in, int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    in >> arr[i];
    if (!in)
    {
      throw std::runtime_error("Error occured while trying to init arr");
    }
  }
}

void miheev::printArrInline(int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}
