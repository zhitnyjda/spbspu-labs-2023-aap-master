#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP
#include <iosfwd>

namespace gorbunova
{
  int readFixedSizeArray(const char* fileName, int(&fixedArray)[100][100], size_t& rows, size_t& cols);
  int readDynamicSizeArray(const char* fileName, int**& dynamicArray, size_t& rows, size_t& cols);
}
#endif
