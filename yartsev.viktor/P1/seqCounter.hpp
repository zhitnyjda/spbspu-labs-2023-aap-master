#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

namespace yartsev {
  struct Counter {
    public:
      void operator()(const int num);
      int getMaxSequence();
    private:
      int maxSequence = 0;
      int currentSequence = 0;
  };
}

#endif
