#include "FindingSubMax.hpp"
#include <stdexcept>

khomichenko::FindingSubMax::FindingSubMax():
  subMax_(0),
  max_(0)
{}

void khomichenko::FindingSubMax::operator()(int num)
{
  if (num != 0)
  {
    if (num > max_)
    {
      subMax_ = max_;
      max_ = num;
    }
    else if (num > subMax_ and num != max_)
    {
      subMax_ = num;
    }
  }
}
size_t khomichenko::FindingSubMax::operator()() const
{
  return subMax_;
}
