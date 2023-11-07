#ifndef COUNTER_MINIMUMS_HPP
#define COUNTER_MINIMUMS_HPP
#include <cstddef>

namespace popov
{
  struct countMinSt
  {
    void count_min();
    void operator()(int a);
    size_t operator()();
  private:
    size_t count_{0};
    int min{0};
  };
}

#endif
