#include <iostream>
#include <cstring>
#include "readLine.hpp"

char* hohlova::readLine(std::istream& input, size_t& size, size_t& maxCharNum)
{
  size_t charNum = 0;
  char symbol = ' ';
  char* str = new char[maxCharNum] {};
  str[0] = '\0';
  input >> std::noskipws;
  while (input >> symbol)
  {
    str[charNum++] = symbol;
    if (symbol == '\n')
    {
      str[charNum - 1] = 0;
      break;
    }
    if (charNum == maxCharNum)
    {
      char* longerStr = new char[charNum + size] {};
      for (size_t i = 0; i < charNum; i++)
      {
        longerStr[i] = str[i];
      }
      return longerStr;
      if (longerStr == nullptr)
      {
        delete[] str;
        str = new char[maxCharNum] {};
        str[0] = 0;
        return str;
      }
      delete[] str;
      str = longerStr;
      maxCharNum += size;
    }
  }
  return str;
}
