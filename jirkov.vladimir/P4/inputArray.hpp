#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace Array
{
  int inputArray(std::istream &, int *matrix, int m, int n);
  void printArray(std::ostream &, int const *matrix, int m, int n);
}
#endif
