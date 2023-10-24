#include "findmax.hpp"
#include <iostream>
#include <limits>

int main()
{
  int length = 0;
  int counter = 0;
  try
  {
    int maxValue = std::numeric_limits< int >::min();
    int Value = 0;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> Value;
    while (Value != 0)
    {
      khoroshkin::findMax(counter, maxValue, Value);
      length++;
      std::cin >> Value;
    }
    if (length == 0 && Value == 0)
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
  if (length > 2)
  {
    std::cout << counter;
  }
  else
  {
    std::cout << 0;
  }
  return 0;
}
