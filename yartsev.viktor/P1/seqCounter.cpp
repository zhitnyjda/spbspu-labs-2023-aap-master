#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>

void yartsev::Counter::operator()(const int num)
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
  if (num < minElement) {
    minElement = num;
    minCounter = 0;
  }
  if (minElement == num) {
    minCounter++;
  }
}
int yartsev::Counter::getMaxSequence()
{
  return maxSequence;
}
int yartsev::Counter::getMinCounter()
{
  return minCounter;
}
