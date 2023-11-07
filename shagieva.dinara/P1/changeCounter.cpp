#include "changeCounter.hpp"
#include <limits>
#include <stdexcept>

shagieva::ChangeCounter::ChangeCounter() : last_number(0), signChange(0)
  {}

void shagieva::ChangeCounter::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (signChange > maxSize)
  {
    throw std::logic_error("The number of sign changes is too big.\n");
  }

  if (number * last_number < 0)
  {
    ++signChange;
  }

   last_number = number;
}

unsigned int shagieva::ChangeCounter::operator()() const
{
  return signChange;
}
