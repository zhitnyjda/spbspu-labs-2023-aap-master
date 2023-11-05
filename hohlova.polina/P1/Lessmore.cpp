#include <iostream>
#include <stdexcept>
#include "Lessmore.hpp"

void hohlova::operator()(int prev, int curr, int next)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (countres_ == maxSize)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  if (curr < prev && curr > next && next != 0 && curr != 0 and prev != 0)
  {
    ++countres_;
  }
}
size_t hohlova::operator()() const
{
  return countres_;
}
