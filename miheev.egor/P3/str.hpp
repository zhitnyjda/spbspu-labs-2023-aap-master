#ifndef STR_HPP
#define STR_HPP

#include "buffer.hpp"
namespace miheev
{
  class String
  {
  public:
    String();
    ~String();
    void expand(size_t size);
    void print() const;
    void fillFromBuff(Buffer buff);
    char* getString() const;

  private:
    char* string_;
    size_t size_;
    size_t indexOfFirstFree_;
  };
}

#endif
