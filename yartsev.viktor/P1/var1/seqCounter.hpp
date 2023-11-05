#ifndef SEQCOUNTER
#define SEQCOUNTER

#include <iostream>
#include <limits>
#include <stdexcept>

namespace yartsev {
struct Counter {
  public:
    void operator()(const int num)
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
    int getMaxSequence()
    {
      return maxSequence;
    }
  private:
    int maxSequence = 0;
    int currentSequence = 0;
};
}

#endif
