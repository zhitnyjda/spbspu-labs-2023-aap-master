#include <iostream>
#include <limits>
#include "Read.hpp"

int Read()
{
  const int max_limit = std::numeric_limits<int>::max();
  const int min_limit = max_limit * -1;
  auto val = 0.0;
  std::cin >> val;
  if (val > max_limit || val < min_limit)
    throw std::overflow_error("Signed owerflow");
  std::cin.exceptions(std::istream::failbit);
  return val;
}
