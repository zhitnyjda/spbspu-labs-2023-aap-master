#include <iostream>
int count_loc_max(std::istream&)
{
  int num;
  if (!(std::cin >> num)) {
    throw std::invalid_argument("Wrong input");
  }
  int lastnum = num;
  int count = 0;
  int flag = 0;
  int length = 0;
  while (num != 0)
  {
    if (num > lastnum) {
      flag = 1;
    } else if (num < lastnum && flag == 1) {
      flag = 0;
      count++;
    }
    length++;
    lastnum = num;
    if (!(std::cin >> num)) {
      throw std::invalid_argument("Wrong input");
    }
  }
