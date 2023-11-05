#include <iostream>
#include "changeCounter.hpp"

int main()
{
  int number;
  using namespace shagieva;
  ChangeCounter changeCounter;

  do
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
        changeCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error:" << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);

  std::cout << changeCounter() << "\n";
  return 0;
}
