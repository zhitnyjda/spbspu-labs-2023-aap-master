#include "maxLen.hpp"
#include <iostream>

psarev::maxLen::maxLen():
  seq_len(0),
  max_len(0),
  prev_value(0)
{}

void psarev::maxLen::operator()(int value)
{
  std::cin.exceptions(std::istream::failbit);

  if (seq_len == 0 && value == 0)
  {
    throw std::logic_error("Error: Not a sequence!\n");
  }

  if (value >= prev_value) {
    seq_len++;
    if (seq_len > max_len) {
      max_len = seq_len;
    }
  }
  else {
    seq_len = 1;
  }

  prev_value = value;
}

int psarev::maxLen::operator()()
{
  return max_len;
}
