#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP
#include <iosfwd>

namespace reznikova
{
  char * inputString(std::istream & in, size_t & size, size_t & add_size);
}

#endif

