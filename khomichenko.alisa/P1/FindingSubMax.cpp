#include "FindingSubMax.hpp"
#include <iostream>
#include <stdexcept>

khomichenko::FindingSubMax::FindingSubMax():
  subMax_(0),
  max_(0),
  seqCount_(0)
{}

void khomichenko::FindingSubMax::operator()(int num)
{
  ++seqCount_;
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

int khomichenko::FindingSubMax::operator()() const
{
  if (seqCount_ <2)
  {
    throw std::logic_error("too short sequence");
  }
  else
  {
    return subMax_;
  }
}
