#ifndef COUNTER_MINIMUMS_HPP
#define COUNTER_MINIMUMS_HPP
#include <cstddef>

namespace popov
{
  struct countMinSt
  {
    countMinSt();
    void operator()(int a);
    size_t operator()();
  private:
    size_t count_;
    int min;
  };
}

#endif
