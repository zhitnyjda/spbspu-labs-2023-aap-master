#ifndef CREATE_LINE_HPP
#define CREATE_LINE_HPP
#include <cstddef>

namespace psarev
{
  size_t createTaskLine(char* line1, const char* line2, size_t len1, size_t len2, char*& lineRes);
};
#endif
