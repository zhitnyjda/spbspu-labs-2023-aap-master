#ifndef COUNTMINSEQUENCE_HPP
#define COUNTMINSEQUENCE_HPP
#include <limits>
#include <cstddef>
#include <fstream>

namespace nikiforov {
  class Sequence
  {
  public:
    void operator()(std::istream& in, int& beforvalue, int& lastvalue);
    size_t printSequence();
  private:
    size_t count = 0;
    int flag = 0;
    const size_t max_count = std::numeric_limits< size_t >::max();
  };
}
#endif
