#include <iostream>
#include "divisibility.hpp"
#include <stdexcept>

int main()
{
  int firstmun, secondnum, count;
  std::cin >> firstmun >> secondnum;
  while (firstmun != 0 && secondnum != 0)
  {
    count += kaseev::divisibility();
    secondnum = firstmun;
  }
}
