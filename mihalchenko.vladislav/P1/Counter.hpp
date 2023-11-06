#ifndef COUNTER_HPP
#define COUNTER_HPP

namespace mihalchenko
{
  struct CounterAfterMax
  {
  public:
    CounterAfterMax();
    void operator()(int number, int seqCounter);
    unsigned int operator()(int seqCounter) const;
  private:
    int fMinus = 0;
    int fPlus = 0;
    int fMaxNum = 0;
    unsigned int countNumAfterMax;
  };
}
#endif // !COUNTER_HPP
