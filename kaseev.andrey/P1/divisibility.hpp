#ifndef DIVISIBILITY_HPP
#define DIVISIBILITY_HPP
#include <iostream>
#include <cstddef>

namespace kaseev
{
  class divisibility
      {
  public:
    divisibility();
    int operator()(int firstnum, int secondnum);
    size_t operator()();
  private:
    int count;
    int firstnum;
    int secondnum;
  };
}

#endif
