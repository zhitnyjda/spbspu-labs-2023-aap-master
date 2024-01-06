#include <iostream>
#include "formingString.hpp"
#include "readingString.hpp"
#include "findRplSym.hpp"

int main()
{
  char * string = nullptr;
  char simbolOld = 'c';
  char simbolNew = 'b';
  int size = 5;
  int newSize = 5;
  string = taskaev::readingString(std::cin, size, newSize);
  if(string == nullptr)
  {
    std::cerr << "Error, bad string." << "\n";
    delete [] string;
    return 1;
  }
  char * resultString = taskaev::findRplSym(string, simbolOld, simbolNew);
  std::cout << resultString << "\n";
  delete[] resultString;
  delete[] string;
  return 0;
}
