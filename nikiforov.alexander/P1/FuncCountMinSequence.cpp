#include <iostream>
#include "CountMinSequence.hpp"

void nikiforov::Sequence::operator()(std::istream& in, int& beforvalue, int& lastvalue)
{
  if (!in)
  {
    throw std::invalid_argument("Wrong input");
  }
  if (count > max_count)
  {
    throw std::overflow_error("Too many sequence elements");
  }
  if (lastvalue < beforvalue) {
    flag = 1;
  }
  else if (lastvalue > beforvalue && flag == 1) {
    flag = 0;
    count++;
  }
  beforvalue = lastvalue;
}

size_t nikiforov::Sequence::operator()() {
  return count;
}
