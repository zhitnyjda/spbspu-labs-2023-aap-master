#ifndef COUNTMINSEQUENCE_HPP
#define COUNTMINSEQUENCE_HPP

namespace nikiforov {
  class Sequence
  {
  public:
    void operator()(int& beforvalue, int& lastvalue);
    int printSequence();
  private:
    size_t count = 0;
    size_t length = 0;
    int flag = 0;
  };
}
#endif