#include "function.hpp"
#include <limits>
#include <stdexcept>
using namespace taskaev;
findmaxCountNumbers::findmaxCountNumbers() :
  count_(0),
  previousNum_(0),
  maxCount_(0),
  countNum_(0)
{}

void findmaxCountNumbers::operator()(int number)
{
  if (maxCount_ == std::numeric_limits< size_t >::max())
  {
    throw std::logic_error("sequence is too long.");
  }
  else {
    if (number == previousNum_) {
      count_++;
    }
    else {
      count_ = 1;
    }
    if (count_ > maxCount_) {
      maxCount_ = count_;
    }
    countNum_ = countNum_ + 1;
    previousNum_ = number;
  }
}
size_t findmaxCountNumbers::operator()() const
{
  return maxCount_;
}
