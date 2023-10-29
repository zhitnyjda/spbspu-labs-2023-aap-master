#include "myFunc.hpp"

namespace psarev
{
  void maxLen(int & value, int & prev_value, int & seq_len, int & max_len)
  {
    if (value >= prev_value) {
      seq_len++;
      if (seq_len > max_len) {
        max_len = seq_len;
      }
    } else {
      seq_len = 1;
    }
  }
}
