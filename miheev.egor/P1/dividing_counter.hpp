#ifndef DIVIDING_COUNTER_H
#define DIVIDING_COUNTER_H

#include <iostream>
#include <cstddef>

namespace miheev
{
  struct DevidingCounter
  {
    int previous;
    std::size_t counter;
    bool seq_is_long_enough;

    DevidingCounter(int previous);
    void operator() (int current);
  };
}

#endif
