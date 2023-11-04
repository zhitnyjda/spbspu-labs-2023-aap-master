#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

#include <stdexcept>

namespace tellez {

  class SequenceCounter {
  private:
    int current_seq_count;
    int max_seq_count;
    int actual;

  public:
    SequenceCounter();
    void operator()(int value);
    size_t operator()() const;
  };

}

#endif
