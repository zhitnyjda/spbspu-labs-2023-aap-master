#include <iostream>
#include <iomanip>
#include <exception>
#include "readString.hpp"
#include "varFunc.hpp"

int main()
{
  int size = 20;
  char * firstInput = new char[size]{};
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (read < size))
  {
    firstInput[read++] = c;
    if (c == '\n')
    {
      firstInput[read - 1] = 0;
      break;
    }
    try
    {
      firstInput =(c != '\n' && read == size)? khomichenko::createBiggerString (&size, firstInput): firstInput;
    }
    catch (std::bad_alloc & e)
    {
      delete [] firstInput;
      return 1;
    }
  }
  std::cin >> std::skipws;
  //DIF-LAT
  std::cout<<khomichenko::countDifLat(firstInput, size)<<"\n";
  char result[size] ={};
  //RMV-VOW
  khomichenko::makingRmvVow(firstInput, size, result);
  for (int i = 0; i < size; i++)
  {
    std::cout<<result[i];
  }
  std::cout<<"\n";
  delete [] firstInput;
  return 0;
}
