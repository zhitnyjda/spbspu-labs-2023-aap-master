#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace Array
{
  int inputArray(std::istream &, int *arr, int m, int n);
  void printArray(std::ostream &, int const *arr, int m, int n);
}
#endif
