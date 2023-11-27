#include <iostream>
#include "formingString.hpp"
#include "readingString.hpp"
#include "findRplSym.hpp"

int main()
{
  char * string = nullptr;
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
  char * answerString = nullptr;
  answerString = taskaev::findRplSym(string);
  std::cout << answerString << "\n";
  delete[] string;
  delete[] answerString;
  return 0;
}
