#ifndef DIVISIBILITY_HPP
#define DIVISIBILITY_HPP
#include <iostream>
#include <cstddef>

namespace kaseev
{
  class divisibility
  {
  public:
    long long int divisibility(long long int, long long int);
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
