#ifndef MAXCHETN_HPP
#define MAXCHETN_HPP
#include <cstddef>
namespace litsinger
{
  struct count_max
  {
    void maxChetn();
    void operator()(int value);
    size_t operator()();
  private:
    size_t counter = 0;
    int max = 0;
  };
}
#endif
