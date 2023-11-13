#ifndef FINDING_SUB_MAX_HPP
#define FINDING_SUB_MAX_HPP
#include <cstddef>

namespace khomichenko
{
  struct FindingSubMax
  {
  public:
    FindingSubMax();
    void operator()(int num);
    int operator()() const;
  private:
    int subMax_=0;
    int max_=0;
    int seqCount_=0;
  };
}
#endif
