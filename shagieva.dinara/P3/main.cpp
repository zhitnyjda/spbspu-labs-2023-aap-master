#include <iostream>
#include <cstddef>
#include "uppLow.hpp"

int main()
{
  char * input = new char[10]{};
  size_t add = 10;
  char cur = 0;
  size_t read = 0;

  std::cin >> std::noskipws;
  do
  {
    std::cin >> cur;
    if (read == 0 && cur == '\n')
    {
      std::cerr << "No line.\n";
      return 1;
    }
    input[read++] = cur;
    if (read % add == 0)
    {
      char * newInput = new char[read + add];
      for (size_t i = 0; i < read; i++)
      {
        newInput[i] = input[i];
      }
      delete [] input;
      input = newInput;
    }
  }
  while (cur != '\n');
  std::cin >> std::skipws;

  char * changedStr = new char[read]{};
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
