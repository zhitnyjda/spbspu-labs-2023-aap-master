#ifndef READLINE_HPP
#define READLINE_HPP
#include <iostream>
#include "comparisonLine.hpp"

namespace nikiforov {
  char* readLine(std::istream& input, char* str1, size_t& lenth);
}

#endif