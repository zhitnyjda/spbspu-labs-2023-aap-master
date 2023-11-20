#ifndef COUNTMINSEQUENCE_HPP
#define COUNTMINSEQUENCE_HPP
#include <limits>
#include <cstddef>
#include <fstream>

namespace nikiforov {
  class Sequence
  {
  public:
    Sequence() {
      count = 0;
      flag = 0;
      max_count = std::numeric_limits< size_t >::max();
    }
    void operator()(std::istream& in, int& beforvalue, int& lastvalue);
    size_t operator()();
  private:
    size_t count;
    int flag;
    size_t max_count;
  };
}
#endif
