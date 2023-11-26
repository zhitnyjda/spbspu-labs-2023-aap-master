#include <iostream>
#include <cstring>
#include <cstddef>
#include <string>
#include "func.hpp"

size_t hohlova::readLine(char* input)
{
  char c = 0;
  std::string s;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[read++] = c;
    s += c;
    if (c == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  return read;
}

size_t hohlova::findCommonChars(std::string s)
{
  int c = 0;
  int i = 0;
  while (i < size(s))
  {
    if (s[i] == s[i + 1])
    {
      c = 1;
      break;
    }
    i++;
  }
  return c;
}
