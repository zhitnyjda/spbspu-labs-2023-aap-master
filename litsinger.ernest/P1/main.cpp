#include "maxchetn.hpp"
#include <iostream>
#include <exception>

int main()
{
  using namespace litsinger;
  countMax maxChetn;
  int value;
  int length = -1;
  do
  {
    std::cin >> value;
    if (std::cin.fail())
    {
      std::cerr << "Input error" << "\n";
      return 1;
    }
    if (value != 0)
    {
      maxChetn(value);
      length++;
    }
    else if (length == -1)
    {
      std::cerr << "Short sequence" << "\n";
      return 2;
    }
  }
  while (value != 0);
  std::cout << maxChetn() << "\n";
  return 0;
}
