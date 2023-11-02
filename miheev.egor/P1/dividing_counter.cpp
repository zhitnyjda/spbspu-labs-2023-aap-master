#include <cstddef>
#include <stdexcept>
#include "dividing_counter.hpp"

miheev::DevidingCounter::DevidingCounter(int previous):
  counter_(0),
  seqIsLongEnough_(false)
{
  initPrevious(previous);
}
void miheev::DevidingCounter::initPrevious(int previous)
{
  if (previous == 0)
  {
    throw std::domain_error("Sequence starts with zero, hence it's too short");
  }
  previous_ = previous;
}
void miheev::DevidingCounter::operator() (int current)
{
  if (current != 0)
  {
    if (!seqIsLongEnough_)
    {
      seqIsLongEnough_ = true;
    }
    if (current%(previous_) == 0)
    {
      counter_++;
    }
  }
  previous_ = current;
}
size_t miheev::DevidingCounter::getCounter()
{
  return counter_;
}
bool miheev::DevidingCounter::getIfSeqLongEnough()
{
  return seqIsLongEnough_;
}
int miheev::DevidingCounter::getPrevious()
{
  return previous_;
}

