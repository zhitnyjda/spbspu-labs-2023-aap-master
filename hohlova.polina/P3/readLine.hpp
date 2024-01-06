#ifndef READLINE_HPP
#define READLINE_HPP
#include <istream>

namespace hohlova
{
  char* readLine(std::istream& input, size_t& size, size_t& maxCharNum);
  extensionOfLine(std::istream& input, size_t size, size_t& maxCharNum);
};
#endif

