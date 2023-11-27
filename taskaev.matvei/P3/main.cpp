#include <iostream>
#include "formingString.hpp"
#include "readingString.hpp"
#include "formingString.hpp"

int main()
{
  char* string = nullptr;
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
  std::cout << taskaev::findRplSym(string) << "\n"; 
  delete[] string;
  return 0;
