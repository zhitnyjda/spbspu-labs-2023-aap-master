#ifndef dilitel_HPP
#define dilitel_HPP
#include <iostream>
#include <cstddef>

namespace kaseev
{
  class delitel
  {
  public:
    delitel();
    int operator()(std::istream &cin);
    size_t operator()();
  private:
    const int max_count;
    int count;
    int firstnum;
    int secondnum;
  };
}

#endif
