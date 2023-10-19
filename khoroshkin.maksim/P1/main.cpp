#include <iostream>
#include <limits>
#include "findmax.hpp"

int main()
{
  int counter = 0;
  int maxValue = std::numeric_limits< int >::min();
  int Value = 0;
  int length = 0;
  try
  {
    do
    {
      std::cin >> Value;
      std::cin.exceptions(std::istream::failbit);
      if (Value != 0)
      {
        findMax(counter, maxValue, Value);
      }
      length++;
    }
    while (Value != 0);
    if (length == 1 && Value == 0)
    {
      throw std::logic_error("Error: not enough values");
    }
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Error: only integer values";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  length > 2 ? std::cout << counter : std::cout << 0;
  return 0;
}
