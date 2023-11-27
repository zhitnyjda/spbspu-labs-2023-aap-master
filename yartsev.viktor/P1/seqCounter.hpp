#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

namespace yartsev {
  struct MinInSequenceCounter {
    public:
      MinInSequenceCounter();
      int operator()();
      void operator()(const int);
    private:
      int minElement;
      int minCounter;
  };
  struct MaxSequenceCounter {
    public:
      MaxSequenceCounter();
      int operator()();
      void operator()(const int);
    private:
      int maxSequence;
      int currentSequence;
  };
}

#endif
