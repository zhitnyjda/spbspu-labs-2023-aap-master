#include "divisibility.hpp"
#include <iostream>
#include <stdexcept>

kaseev::divisibility::divisibility():
    count(0),
    firstNum(),
    secondNum()
{}

int kaseev::divisibility::operator()(int firstNum, int secondNum)
{
  while (secondNum != 0 && firstNum != 0)
  {
    if (secondNum % firstNum == 0)
    {
      count += 1;
    }
    firstNum = secondNum;
    if (!(std::cin >> secondNum))
    {
      throw std::logic_error("Wrong input");
    }
  }
  return count;
}
void kaseev::divisibility::operator()(int count)
{
  std::cout << count << "\n";
}

