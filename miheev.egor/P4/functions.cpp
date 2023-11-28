#include "functions.hpp"
#include <iostream>
#include "matrix_methods.hpp"

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

void miheev::extendStringWithArr(int* arr, size_t size, std::string& str)
{
  for (size_t i = 0; i < size; i++)
  {
    str += ' ' + std::to_string(arr[i]);
  }
}

std::string miheev::getIncreasedMatrixInline(int* arr, size_t rows, size_t cols)
{
  miheev::increasePeriphery(arr, rows, cols);
  std::string increasedMatrix("");
  miheev::extendStringWithArr(arr, rows*cols, increasedMatrix);
  return increasedMatrix;
}
