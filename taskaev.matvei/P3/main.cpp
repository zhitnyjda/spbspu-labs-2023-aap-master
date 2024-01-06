#include <iostream>
#include "formingString.hpp"
#include "readingString.hpp"
#include "findRplSym.hpp"

int main()
{
  char * string = nullptr;
  char simbolOld = '0';
  char simbolNew = '0';
  int size = 5;
  int newSize = 5;
  string = taskaev::readingString(std::cin, size, newSize);
  if(string == nullptr)
  {
    std::cerr << "Error, bad string." << "\n";
    delete [] string;
    return 1;
  }
  std::cin >> simbolOld;
  std::cin >> simbolNew;
  char * resultString = taskaev::findRplSym(string, simbolOld, simbolNew);
  std::cout << resultString << "\n";
  delete[] resultString;
  delete[] string;
  return 0;
}
