#include <iostream>
#include <limits>
#include <stdexcept>
#include "Counter.hpp"

mihalchenko::CounterAfterMax::CounterAfterMax()
{
  countNumAfterMax = 0;
  fMinus = 0;
  fPlus = 0;
  fMaxNum = 0;
}

void mihalchenko::CounterAfterMax::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (countNumAfterMax == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  (number > fMaxNum) ? (fMaxNum = number, countNumAfterMax = 0) : (countNumAfterMax += 1);
  (number < 0) ? (fMinus += 1) : (fPlus += 1);
  //++countNumAfterMax;
}

unsigned int mihalchenko::CounterAfterMax::operator()() const
{
  if ((fMinus == 0) || (fPlus == 0))
  {
    std::cerr << "The sequence includes numbers of the same sign";
    return 1;
  }
  return countNumAfterMax;
}
