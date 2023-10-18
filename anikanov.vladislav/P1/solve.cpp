#include "solve.hpp"
#include <iostream>
#include <limits>

void solving(long long &count)
{
  const long long max_count = std::numeric_limits<long long>::max();
  long long min_member = max_count;
  long long number;
  if (!(std::cin >> number)) throw std::invalid_argument("Wrong input");
  while (number != 0) {
    if (number == min_member && count < max_count) ++count;
    if (number == min_member && count == max_count) throw std::overflow_error("To much minimal numbers");
    if (number < min_member) {
      min_member = number;
      count = 1;
    }
    if (!(std::cin >> number)) throw std::invalid_argument("Wrong input");
  }
}
