#ifndef RESIZE_ARRAY_HPP
#define RESIZE_ARRAY_HPP
#include <cstddef>
#include <istream>

namespace doroshenko
{
  char* resizeArray(char*, size_t, size_t);
  void removeDup(char* input, size_t readEl);
  size_t readInput(char* input, std::istream& in);
}

#endif
