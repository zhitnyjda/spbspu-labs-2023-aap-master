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
    if (string[0] == '\0')
    {
      delete[] string;
      throw std::logic_error("Not string");
    }
  }
  catch( const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << taskaev::findRplSym(string) << "\n"; 
  delete[] string;
  return 0;
