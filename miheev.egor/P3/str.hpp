#ifndef STR_HPP
#define STR_HPP

#include "buffer.hpp"
namespace miheev
{
  class String
  {
  public:
    String();
    void expand(size_t size);
    void print();
    void fillFromBuff(Buffer buff);

  private:
    char* string_;
    size_t size_;
    size_t indexOfFirstFree_;
  };
}

#endif
