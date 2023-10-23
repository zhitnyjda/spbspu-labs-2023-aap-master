#include <iostream>
#include "function.hpp"
int maxCountNumbers(int num)
{
  int count = 0;
  int previousNum = 0;
  int maxCount = 0;
  int countNum = 1;
  while (num !=0 )
  {
    previousNum = num;
    std::cin >> num;
    if (num == previousNum) {
      count++;
    }
    else {
      count = 1;
    }
    if (count > maxCount) {
      maxCount = count;
    }
    countNum=countNum +1;
  }
  if (!std::cin) {
    throw std::invalid_argument("Error occured.");
  }
  if (countNum < 3) {
    throw std::overflow_error("Error, short sequence.");
  }
  return maxCount;
}
