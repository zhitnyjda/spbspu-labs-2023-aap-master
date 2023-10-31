#ifndef DIVIDING_COUNTER_H
#define DIVIDING_COUNTER_H
#include <cstddef>

namespace miheev
{
  struct DevidingCounter
  {
  private:
    int previous_;
    size_t counter_;
    bool seqIsLongEnough_;

  public:
    DevidingCounter(int previous);
    void initPrevious(int previous);
    void operator() (int current);
    size_t getCounter();
    bool getIfSeqLongEnough();
    int getPrevious();
  };
}
#endif

