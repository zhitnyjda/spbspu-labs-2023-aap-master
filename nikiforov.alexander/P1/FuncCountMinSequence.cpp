#include <iostream>
#include "CountMinSequence.hpp"

void nikiforov::Sequence::operator()(int& beforvalue, int& lastvalue)
{
  if (lastvalue < beforvalue) {
    flag = 1;
  }
  else if (lastvalue > beforvalue && flag == 1) {
    flag = 0;
    count++;
  }
  length++;
  beforvalue = lastvalue;
}

int nikiforov::Sequence::printSequence() {
  return count;
}
