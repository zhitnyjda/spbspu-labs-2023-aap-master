#include <iostream>
#include <iomanip>
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
    firstInput =(c != '\n' && read == size)? khomichenko::createBiggerString (&size, firstInput): firstInput;
  }
  std::cin >> std::skipws;
  std::cout<<khomichenko::countDifLat(firstInput, size)<<"\n";
  delete [] firstInput;
  return 0;
}
