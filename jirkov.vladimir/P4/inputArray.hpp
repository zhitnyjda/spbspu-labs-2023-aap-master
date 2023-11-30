#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace Array
{
  size_t inputArray(std::istream &, int *matrix, size_t Size);
  void printArray(std::ostream &, int const *matrix, size_t m, size_t n);
}
#endif
