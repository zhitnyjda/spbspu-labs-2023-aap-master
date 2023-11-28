#include <iostream>
#include "fun.hpp"
int main()
{ 
  size_t size = 10;
  size_t counter = 0;
  char * pointer = new char[size];  
  char current_char = '0';
  std::cin >> std::noskipws;
  while (std::cin >> current_char && current_char != '\n')
  {
    if(counter >= size)
    {
      try 
      {
        pointer = seryj::changeArray(pointer, size);
      }
      catch (std::logic_error const& e)
      {
        delete[] pointer;
        std::cerr << e.what();
        return 1;
      }
      size *= 2;
    }
    pointer[counter] = current_char;
    counter++;
  }
  int answer = seryj::streql(pointer, counter);
  std::cout << "Found " << answer << " pair" << (answer != 1 ? "s" : "") << " of equal symbols\n";
  delete[] pointer;
  std::cin >> std::skipws;
  return 0;
}
