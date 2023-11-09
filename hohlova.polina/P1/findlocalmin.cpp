#include <stdexcept>
#include <limits>
#include "findlocalmin.hpp"

hohlovaa::FindLocalMin::FindLocalMin():
  countmins_(0)
{}
void hohlovaa::FindLocalMin::operator()(int prev, int curr, int next)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (countmins_ == maxSize)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  if (curr < prev && curr < next && next != 0 && curr != 0 && prev != 0)
  {
    ++countmins_;
  }
}
size_t hohlovaa::FindLocalMin::operator()() const
{
  return countmins_;
}
