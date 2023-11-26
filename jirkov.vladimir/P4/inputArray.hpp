#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace Array
{
  size_t inputArray(std::istream &cin, int *matrix, size_t s, size_t inputElements);
  void printArray(std::ostream &cout, int *matrix, size_t m, size_t n);
}
#endif
