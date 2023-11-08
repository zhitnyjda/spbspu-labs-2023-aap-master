#ifndef MAXLEN_H
#define MAXLEN_H
#include <cstddef>

namespace psarev
{
  class maxLen
  {
  public:
    maxLen();
    void operator()(int value);
    int operator()();

  private:
    size_t seq_len;
    size_t max_len;
    int prev_value;
  };
}
#endif
