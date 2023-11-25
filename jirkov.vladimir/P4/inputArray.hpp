#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
namespace jirkov
{
  size_t inputArray(std::istream &in, int *matrix, size_t s, size_t inputElements);
  void printArray(std::ofstream &out, int *matrix, size_t m, size_t n);
}
#endif
