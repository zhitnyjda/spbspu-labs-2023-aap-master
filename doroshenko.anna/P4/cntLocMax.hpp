#ifndef CNT_LOC_MAX_HPP
#define CNT_LOC_MAX_HPP
#include <iosfwd>

namespace doroshenko
{
  long long readingArguments(char**);
  size_t inputArray(std::istream&, int*, size_t);
  size_t findingLocMax(const int*, size_t, size_t);
}

#endif
