#include "findingCount.hpp"
#include <iostream>
#include <stdexcept>
jirkov::FindingCount::FindingCount():
  lenghts_(2),
  count_(0)
{}
void jirkov::FindingCount::operator()(size_t prev, size_t current, size_t next)
{
  count_ += ((prev > current && current > next) ? 1 : 0);
  lenghts_ += 1;
}
size_t jirkov::FindingCount::operator()() const
{
  if (lenghts_ < 3)
  {
    throw std::logic_error("Too short sequence\n");
  }
  else
  {
    return count_;
  }
}
