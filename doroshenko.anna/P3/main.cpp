#include <iostream>
#include <iomanip>
#include <iosfwd>
#include "functions.hpp"
int main()
{
  char* input = new char[20];
  try
  {
    size_t readEl = 0;
    std::cin >> std::noskipws;
    readEl = doroshenko::readInput(input, std::cin);
    if (readEl == 0)
    {
      std::cerr << "There is no elements in the string\n";
      return 1;
    }
    doroshenko::removeDup(input, readEl);
    std::cin >> std::skipws;
    delete[] input;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation error\n";
    delete[] input;
    return 1;
  }
}
