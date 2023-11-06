#include <iostream>
#include <typeinfo>
#include "Counter.hpp"

int main()
{
  int number = -1;
  
  using namespace mihalchenko;

  CounterAfterMax counterAfterMax;
  while (number != 0)
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counterAfterMax(number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  std::cout << counterAfterMax() << "\n";
  return 0;
}
