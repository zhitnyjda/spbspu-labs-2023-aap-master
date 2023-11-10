#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

#include<limits>

namespace yartsev {
  struct Counter {
    public:
      void operator()(const int num);
      int getMaxSequence();
      int getMinCounter();
    private:
      int maxSequence = 0;
      int currentSequence = 0;
      int minElement = std::numeric_limits< int >::max();
      int minCounter = 0;
  };
}

#endif
