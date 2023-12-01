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
      try
      {
        values = seryj::changeArray(values, size);
      }
      catch (std::logic_error const & e)
      {
        delete[] values;
        std::cerr << e.what();
        return 1;
      }
      size *= 2;
    }
    values[counter] = current_char;
    counter++;
  }
  size_t answer = seryj::counterOfEqualPairs(values, counter);
  std::cout << "Found " << answer << " pair" << (answer != 1 ? "s" : "") << " of equal symbols\n";
  delete[] values;
  std::cin >> std::skipws;
  return 0;
}
