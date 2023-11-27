#ifndef LINE_FUNCS_HPP
#define LINE_FUNCS_HPP
#include <cstddef>

namespace psarev
{
  size_t makeLine(char*& line);
  size_t makeMutUnLine(char* line1, char* line2, size_t len1, size_t len2, char* lineRes);
};
#endif
