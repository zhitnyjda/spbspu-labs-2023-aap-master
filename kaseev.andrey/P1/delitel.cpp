#include "delitel.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

int delitel(std::istream &cin)
{
  const int max_count = std::numeric_limits<int>::max();
  int count = 0;
  int firstnum;
  int secondnum;
  if (!(std::cin >> firstnum) || firstnum == 0) {
    throw std::logic_error("Wrong input");
  }
  if (!(std::cin >> secondnum)) {
    throw std::logic_error("Wrong input");
  }
  if (firstnum == 0 || secondnum == 0) {
    throw std::logic_error("Not enough elements");
  }
  while (secondnum != 0 && firstnum != 0) {
    if (secondnum % firstnum == 0) {
      count += 1;
    }
    firstnum = secondnum;
    if (count > max_count) {
      throw std::overflow_error("Too many numbers");
    }
    if (!(cin >> secondnum)) {
      throw std::logic_error("Wrong input");
    }
  }
  return count;
}
