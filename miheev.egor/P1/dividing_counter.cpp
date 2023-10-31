#include <cstddef>
#include <stdexcept>
#include "dividing_counter.hpp"

miheev::DevidingCounter::DevidingCounter(int previous):
  counter_(0),
  seqIsLongEnough_(false)
{
  (this->initPrevious)(previous);
}
void miheev::DevidingCounter::initPrevious(int previous)
{
  if (previous == 0)
  {
    throw std::domain_error("Sequence starts with zero, hence it's too short");
  }
  this->previous_ = previous;
}
void miheev::DevidingCounter::operator() (int current)
{
  if (current != 0)
  {
    if (!this->seqIsLongEnough_)
    {
      this->seqIsLongEnough_ = true;
    }
    if (current%(this->previous_) == 0)
    {
      (this->counter_)++;
    }
  }
  this->previous_ = current;
}
size_t miheev::DevidingCounter::getCounter()
{
  return this->counter_;
}
bool miheev::DevidingCounter::getIfSeqLongEnough()
{
  return this->seqIsLongEnough_;
}
int miheev::DevidingCounter::getPrevious()
{
  return this->previous_;
}

