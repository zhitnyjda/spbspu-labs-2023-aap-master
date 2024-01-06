#include <iostream>
#include "formingString.hpp"
#include "readingString.hpp"
#include "findRplSym.hpp"

int main()
{
  char * string = nullptr;
  char simbolOld = '0';
  char simbolNew = '0';
  try
  {
    string = taskaev::readingString(std::cin);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    delete [] string;
    return 1;
  }
  std::cin >> simbolOld;
  std::cin >> simbolNew;
  std::cout << taskaev::findRplSym(string, simbolOld, simbolNew) << "\n";
  delete[] string;
  return 0;
}
