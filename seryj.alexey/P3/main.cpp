#include <iostream>
#include "fun.hpp"
int main()
{
  size_t size = 10;
  size_t counter = 0;
  char * values = new char[size];
  char current_char = '0';
  std::cin >> std::noskipws;
  while (std::cin >> current_char && current_char != '\n')
  {
    if(counter >= size)
    {
      char * new_values = seryj::changeArray(values, size);
      if (!new_values)
      {
        std::cerr << "Not enough space for arran\n";
        delete[] values;
        delete[] new_values;
        return 1;
      }
      delete[] values;
      values = new_values;
      size *= 2;
    }
    values[counter++] = current_char;
  }
  if (!counter)
  {
    std::cerr << "Error: zero sequence\n";
    delete[] values;
    return 1;
  }
  size_t answer = seryj::counterOfEqualPairs(values, counter);
  std::cout << "Found " << answer << " pair" << (answer != 1 ? "s" : "") << " of equal symbols\n";
  delete[] values;
  std::cin >> std::skipws;
  return 0;
}
