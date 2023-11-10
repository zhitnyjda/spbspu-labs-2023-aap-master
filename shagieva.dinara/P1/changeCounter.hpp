#ifndef CHANGE_COUNTER_HPP
#define CHANGE_COUNTER_HPP

namespace shagieva
{
  struct ChangeCounter
  {
  public:
    ChangeCounter();
    void operator()(int number);
    unsigned int operator()() const;

  private:
    int last_Number;
    unsigned int signChange;
  };
}
#endif
