#include "Header.hpp"
#include <iostream>

int func(std::istream&)
{
  int n = 0;
  int num = 0;
  if (!(std::cin >> num)) {
    throw std::invalid_argument("Wrong input");
  }
  int beforenum = num;
  int count = 0;
  int flag = 0;
  int length = 0;
  while (num != 0)
  {
    if (num < beforenum) {
      flag = 1;
    } else if (num > beforenum && flag == 1) {
      flag = 0;
      count++;
    }
    length++;
    beforenum = num;
    if (!(std::cin >> num)) {
      throw std::invalid_argument("Wrong input");
    }
  }
  return count;
}
