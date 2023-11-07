#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP
#include <stdexcept>

namespace tellez
{
  class LongestDecreasingCounter {
  private:
    int current_seq_count;
    int max_seq_count;
    int actual;
  public:
    LongestDecreasingCounter();
    void processValue(int value);
    size_t getLongestSequenceLength() const;
  };
}
#endif
