#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <cctype>
#include "readString.hpp"
#include "varFunc.hpp"

int main()
{
  using namespace khomichenko;
  int size = 20;
  char * firstInput = new char[size]{};
  char c = 0;
  int read = 0;
  std::cin >> std::noskipws;
  if (!std::cin)
  {
    std::cerr<<"input failed\n";
    delete [] firstInput;
    return 1;
  }
  while (std::cin>>c && read < size)
  {
    firstInput [read++] = c;
    if (c == '\n')
    {
      firstInput [read - 1] = 0;
      break;
    }
    if (c != '\n' && read >= size)
    {
      try
      {
        char * secondInput = new char [size + size] {};
//        std::swap(firstInput, secondInput);
swapStrings(firstInput, secondInput, (size));
       size += size;
        delete [] firstInput;
        firstInput = new char [size] {};
//        std::swap(firstInput, secondInput);
swapStrings(secondInput, firstInput, size);
        delete [] secondInput;
      }
      catch (std::bad_alloc & e)
      {
        delete [] firstInput;
        return 1;
      }
    }
  }
  if (read < 2)
  {
    std::cerr << "empty input\n";
    delete [] firstInput;
    return 1;
  }
  std::cin >> std::skipws;
  std::cout << khomichenko::countDifLat(firstInput)<<"\n";
  char result [size] = {};
  khomichenko::makingRmvVow(firstInput, result);
  for (int i = 0; i < size; i++)
  {
    std::cout << result[i];
  }
  std::cout<<"\n";
  delete [] firstInput;
  return 0;
}
