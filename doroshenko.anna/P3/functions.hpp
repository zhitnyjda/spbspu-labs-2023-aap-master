#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cstddef>
#include <iostream>

namespace doroshenko
{
  char* resizeArray(char*, size_t, size_t);
  size_t readInput(char* input, std::istream& in);
  void removeDup(char* input, size_t readEl);
}

#endif
