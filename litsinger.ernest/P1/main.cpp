#include "maxcount.hpp"
#include <iostream>
#include <exception>

int main()
{
  int max = 0;
  try
  {
    int counter = 0;
    int length = -1;
    int value = 1;
    std::cin.exceptions(std::istream::failbit);
    while (value != 0)
    {
      std::cin >> value;
      maxCount(counter, max, value);
      length++;
    }
    if (length == 0)
    {
      std::cout << "Short sequence" << "\n";
      return 2;
    }
    std::cout << counter << "\n";
    return 0;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }
}