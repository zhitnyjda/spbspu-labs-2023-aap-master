#include "findingCount.hpp"
#include <iostream>

int findingCount()
{
  int countNums = 0;
  int countSum = 0;
  int number1 = 0;
  int number2 = 0;
  int value = 0;

  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      throw std::invalid_argument("Wrong input\n");
    }
    else
    {
      countNums += (value != 0 ? 1 : 0);
      countSum += (value == number1 + number2 ? 1 : 0);
      number1 = number2;
      number2 = value;
    }
  }
  while (value && std::cin);

  if (countNums < 3)
  {
    throw std::logic_error("Too short sequence");
  }
  else
  {
    return countSum;
  }
}
