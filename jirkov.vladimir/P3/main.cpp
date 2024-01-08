#include <iostream>
#include <cstring>
#include "inputString.hpp"
#include "checkDuplicatesChars.hpp"

int main()
{
  size_t scope = 10;
  size_t size = 0;
  char* string = inputString(std::cin);
  if (string == nullptr)
  {
    std::cerr << "String reading error\n";
    return 1;
  }
  size_t Result = checkDuplicatesChars(string);
  std::cout << Result << '\n';
  delete[] string;
  return 0;
}
