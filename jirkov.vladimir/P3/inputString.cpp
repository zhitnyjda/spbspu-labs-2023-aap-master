#include "inputString.hpp"
#include <iostream>
#include <cstring>

char* increaseScope(const char* string, size_t newSize, size_t& newScope)
{
  newScope = newSize * 2;
  char* newString = new char[newScope];
  std::memset(newString, 0, newScope);
  std::memcpy(newString, string, newSize + 1);
  return newString;
}

char* inputString(std::istream& input, const size_t& size, size_t& scope)
{
  char* string = new char[scope];
  string[0] = '\0';
  input >> std::noskipws;
  size_t newSize = size;
  do
  {
    if (newSize == scope)
    {
      char* newString = increaseScope(string, size, scope);
      if (newString == nullptr)
      {
        std::cout << "Dynamic memory error\n";
        delete[] string;
        return nullptr;
      }
      delete[] string;
      string = newString;
      newString = nullptr;
    }
    input.get(string[newSize]);
  }
  while (input && string[newSize++] != '\n');
  if (string[0] == '\0' || string[0] == '\n')
  {
    std::cout << "Input error\n";
    delete[] string;
    return nullptr;
  }
  return string;
}
