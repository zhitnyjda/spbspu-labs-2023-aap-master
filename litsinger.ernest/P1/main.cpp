#include <iostream>
#include <exception>
#include "maxchetn.hpp"

int main()
{
  using namespace litsinger;
  countMax maxChetn;
  int value;
  int size_t = 0;
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
      size_t++;
    }
    else if (size_t == 0)
    {
      std::cerr << "Short sequence" << "\n";
      return 2;
    }
  }
  while (value != 0);
  std::cout << maxChetn() << "\n";
  return 0;
}
