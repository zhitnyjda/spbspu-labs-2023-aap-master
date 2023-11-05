#ifndef DIV_COUNTER_HPP
#define DIV_COUNTER_HPP

namespace shagieva
{
  struct DivCounter
  {
  public:
    DivCounter();
    void operator()(int number);
    unsigned int operator()() const;

  private:
    int last_number;
    unsigned int serial_number;
    unsigned int count;
  };
}
#endif

