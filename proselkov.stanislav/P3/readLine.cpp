#include "readLine.hpp"
#include <iostream>
#include <cstddef>

size_t readLine(char * input)
{
  char symbol = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> symbol)
  {
    input[read++] = symbol;
    if (symbol == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  return read;
}
