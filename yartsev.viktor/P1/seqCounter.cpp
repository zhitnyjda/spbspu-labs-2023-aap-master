#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

yartsev::MinInSequenceCounter::MinInSequenceCounter():
  minElement(std::numeric_limits< int >::max()),
  minCounter(0)
{}

int yartsev::MinInSequenceCounter::operator()()
{
  return minCounter;
}

void yartsev::MinInSequenceCounter::operator()(const int num)
{
  if (num < minElement) {
    minElement = num;
    minCounter = 0;
  }
  if (minElement == num) {
    minCounter++;
  }
}

yartsev::MaxSequenceCounter::MaxSequenceCounter():
  maxSequence(0),
  currentSequence(0)
{}

int yartsev::MaxSequenceCounter::operator()()
{
  return maxSequence;
}

void yartsev::MaxSequenceCounter::operator()(const int num)
{
  const int maxSize = std::numeric_limits< int >::max();
  if (num % 2 == 0) {
    if (currentSequence == maxSize) {
      throw std::overflow_error("Sequence is too long");
    } else {
      currentSequence++;
    }
  } else {
    currentSequence = 0;
  }
  maxSequence = std::max(maxSequence, currentSequence);
}
