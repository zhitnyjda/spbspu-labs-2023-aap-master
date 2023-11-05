#include "divCounter.hpp"
#include <limits>
#include <stdexcept>

shagieva::DivCounter::DivCounter()
  {
    last_number = 0;
    serial_number = 0;
    count = 0;
  }

void shagieva::DivCounter::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (count > maxSize)
  {
    throw std::logic_error("The result is too big.\n");
  }

  ++serial_number;

  if (serial_number != 1)
  {
    if (number % last_number == 0)
    {
      ++count;
    }
  }

  last_number = number;
}

unsigned int shagieva::DivCounter::operator()() const
{
  return count;
}
