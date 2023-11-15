#include "findingCount.hpp"
#include <iostream>
#include <stdexcept>
jirkov::FindingCount::FindingCount():
  count_(0),
  firstNum_(0),
  secondNum_(0)
{}
void jirkov::FindingCount::operator()(size_t value)
{
  count_ += ((firstNum_ > secondNum_ && secondNum_ > value) ? 1 : 0);
  firstNum_ = secondNum_;
  secondNum_ = value;
}
size_t jirkov::FindingCount::operator()() const
{
  return count_;
}
