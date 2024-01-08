#include <iostream>
#include <cstring>
#include "inputString.hpp"

char* resizeString(char* string, size_t currentSize, size_t newSize)
{
  char* newString = new char[newSize];
  if (newString == nullptr)
  {
    std::cerr << "Dynamic memory error\n";
    delete[] string;
    return nullptr;
  }
  for (size_t i = 0; i < currentSize; i++)
  {
    newString[i] = string[i];
  }
  delete[] string;
  return newString;
}

char* inputString(std::istream& input)
{
  const size_t initialSize = 10;
  size_t size = 0;
  size_t scope = initialSize;
  char* string = new char[scope];
  string[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size == scope)
    {
      char* newString = resizeString(string, scope, scope * 2);
      if (newString == nullptr)
      {
        delete[] string;
        return nullptr;
      }
      string = newString;
    }
    input >> string[size];
    if (input.eof())
    {
      break;
    }
    size++;
  }
  while (string[size - 1] != '\n');
  if (string[0] == '\0' || string[0] == '\n')
  {
    std::cerr << "Input error\n";
    delete[] string;
    return nullptr;
  }
  return string;
}
