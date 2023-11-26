#include <iostream>
#include <cctype>
#include "functions.hpp"

size_t zheleznyakov::readLine(char * input)
{
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[read++] = c;
    if (c == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  return read;
}
