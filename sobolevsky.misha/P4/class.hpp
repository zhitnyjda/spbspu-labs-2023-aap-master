#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>

namespace sobolevsky
{
  class Arrays
  {
  public:
    size_t size;
    int statArray[10000];
    int * dynArray;

    Arrays(size_t size);
    Arrays(size_t rows, size_t cols);
  };
}

#endif