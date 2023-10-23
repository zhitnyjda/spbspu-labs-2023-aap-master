#include <iostream>
#include <exception>
#include "maxchetn.hpp"

int main()
{
  int countMax = 0;
  try
  {
    int counter = 0;
    int number = 1;
    std::cin.exceptions(std::istream::failbit);
    while (number != 0)
    {
      std::cin >> number;
      maxChetn(counter, countMax, number);
    }
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Enter only int\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << countMax << "\n";
  return 0;
}
