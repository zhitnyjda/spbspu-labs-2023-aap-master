#include "divisibility.hpp"
#include <iostream>
#include <stdexcept>

kaseev::divisibility::divisibility():
    count(0),
    firstnum(),
    secondnum()
{}

int kaseev::divisibility::operator()(int firstnum, int secondnum)
{
  while (secondnum != 0 && firstnum != 0)
  {
    if (secondnum % firstnum == 0)
    {
      count += 1;
    }
    firstnum = secondnum;
    if (!(std::cin >> secondnum))
    {
      throw std::logic_error("Wrong input");
    }
  }
  return count;
}
