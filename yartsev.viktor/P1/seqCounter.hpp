#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

#include<limits>

namespace yartsev {
  struct SequenceCounter {
    public:
      void operator()();
      void operator()(const int num);
    private:
      int maxSequence = 0;
      int currentSequence = 0;
      int minElement = std::numeric_limits< int >::max();
      int minCounter = 0;
  };
}

#endif
