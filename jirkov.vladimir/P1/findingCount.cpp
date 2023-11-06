#include "findingCount.hpp"
jirkov::FindingCount::FindingCount()
{
  lenghts = 2;
  count_ = 0;
}
void jirkov::FindingCount::operator()(size_t prev, size_t current, size_t next)
{
  count_ += ((prev > current && current > next) ? 1 : 0);
  lenghts += 1;
}
size_t jirkov::FindingCount::operator()()
{
  return count_;
}
