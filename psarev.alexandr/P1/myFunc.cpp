#include "myFunc.hpp"

psarev::maxLen::maxLen():
  seq_len(0), max_len(0), prev_value(0)
{}

void psarev::maxLen::operator()(int value)
{
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
