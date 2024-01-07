#ifndef STRING_HPP
#define STRING_HPP
#include "cstddef"

namespace miheev
{
  void expandString(char** toExpand, size_t& receiverSize, size_t additionalSize);
  size_t readString(char **receiver);
}

#endif
