#include "CountMinSequence.hpp"
#include <limits>

void nikiforov::Sequence::operator()(int& value)
{
  if (count > max_count)
  {
    throw std::overflow_error("Too many sequence elements\n");
  }
  if (value < beforvalue) {
    flag = 1;
  }
  else if (value > beforvalue && flag == 1 && value != 0) {
    flag = 0;
    count++;
  }
  beforvalue = value;
}

size_t nikiforov::Sequence::operator()() {
  return count;
}
