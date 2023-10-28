#include <iostream>
#include "main.hpp"

int main()
{
  SomeFunctor COUNT;
  long long value = 0;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Wrong input.\n";
      return 1;
    }
    else if (value != 0)
    {
      try
      {
        COUNT(value);;
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
      }
    }
  }
  while (value != 0);
  std::cout << COUNT.functor() << "\n";
  return 0;
}
