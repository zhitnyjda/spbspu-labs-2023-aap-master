#ifndef DIVISIBILITY_HPP
#define DIVISIBILITY_HPP
#include <iostream>

namespace kaseev
{
  class divisibility
  {
  public:
    divisibility();
    int operator()(int firstNum, int secondNum);
    void operator()(int count);
  private:
    int count;
    int firstNum;
    int secondNum;
  };
}

#endif
