#include "evenNumber.hpp"

gorbunova::EvenNumber::EvenNumber():
  count_(0),
  maxCount_(0)
{}

void gorbunova::EvenNumber::operator()(size_t value)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (count_ == maxSize)
  {
    throw std::logic_error("Too long sequence\n");
  }
  if (value % 2 == 0)
  {
    count_++;
  }
  else
  {
    count_ = 0;
  }
}

size_t gorbunova::EvenNumber::operator()()
{
  if (maxCount_ < count_)
  {
    maxCount_ = count_;
  }
  return maxCount_;
}
