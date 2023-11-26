#include <iostream>
#include <cstddef>
#include "uppLow.hpp"

int main()
{
  char * input = new char[10]{};
  char cur = 0;
  size_t read = 0;

  std::cin >> std::noskipws;
  while ((std::cin >> cur) && (read < 9))
  {
    input[read++] = cur;
    if (cur == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;

  char * changedStr = new char[10]{};
  shagieva::uppLow(input, changedStr, read);

  for (size_t i = 0; i < read; i++)
  {
    std::cout << changedStr[i];
  }
  std::cout << "\n";

  delete[] input;
  delete[] changedStr;
  return 0;
}
