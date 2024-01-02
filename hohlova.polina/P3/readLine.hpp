#ifndef READLINE_HPP
#define READLINE_HPP
#include <istream>
#include <cstddef>

namespace hohlova
{
  char* readLine(std::istream& inputstring, size_t& size, size_t& chars);
};
#endif
