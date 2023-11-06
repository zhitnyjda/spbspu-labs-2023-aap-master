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

void mihalchenko::CounterAfterMax::operator()(int number, int fseqCounter)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  fseqCounter = 0;
  if (countNumAfterMax == maxSize)
  {
    throw std::logic_error("Sequence is too long");
  }
  (number > fMaxNum) ? (fMaxNum = number, countNumAfterMax = 0) : (countNumAfterMax += 1);
  (number < 0) ? (fMinus += 1) : (fPlus += 1);
}

unsigned int mihalchenko::CounterAfterMax::operator()(int seqCounter) const
{
  if (((fMinus == 0) || (fPlus == 0)) && (seqCounter > 1))
  {
    std::cerr << "The sequence includes numbers of the same sign\n";
    return 1;
  }
  if (seqCounter > 1)
    return countNumAfterMax;
  else
  {
    std::cerr << "The sequence is empty\n";
    return 2;
  }
}
