#include "inputString.hpp"
#include <iostream>
#include <iomanip>

char * sukacheva::inputString(std::istream& in)
{
  size_t len = 10;
  char* input = new char[len] {};
  size_t read = 0;
  char c = 0;
  in >> std::noskipws;
  while (in.get(c))
  {
    if (read == len - 1)
    {
      len += 10;
      char* newInput = new char[len] {};
      std::copy(input, input + read, newInput);
      delete[] input;
      input = newInput;
    }
    if (c == '\n')
    {
      break;
    }
    input[read] = c;
    read++;
  }
  in >> std::skipws;
  return input;
}