#ifndef DIVIDING_COUNTER_H
#define DIVIDING_COUNTER_H
#include <cstddef>

namespace miheev
{
  struct DevidingCounter
  {
  public:
    DevidingCounter(int previous);
    void checkFirstPrevious();
    void operator() (int current);
    size_t getCounter();
    bool getIfSeqLongEnough();
    int getPrevious();

  private:
    int previous_;
    size_t counter_;
    bool seqIsLongEnough_;
  };
}
#endif

