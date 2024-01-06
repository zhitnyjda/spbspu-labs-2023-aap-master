#include <iostream>
#include <cstring>
#include "readLine.hpp"

char* hohlova::readLine(std::istream& input, size_t& size, size_t& maxCharNum)
{
  char* str = new char[maxCharNum];
  str[0] = ' ';
  input >> std::noskipws;
  do
  {
    if (size == maxCharNum)
    {
      char* longerStr = new char[maxCharNum + size] {};
      str = hohlova::extensionOfLine(size, maxCharNum);
    }
    std::cin >> str[size];
  } while (str[size++] != '\n');
  if (str[0] == '\0' || str[0] == '\n')
  {
    return nullptr;
  }
  return str;
}

char* hohlova::extensionOfLine(size_t& size, size_t& maxCharNum)
{
  char* str = new char[maxCharNum];
  char* longerStr = new char[maxCharNum + size] {};
  for (size_t i = 0; i < maxCharNum; i++)
  {
    longerStr[i] = str[i];
  }
  maxCharNum += size;
  delete[] str;
  str = longerStr;
  return str;
}
