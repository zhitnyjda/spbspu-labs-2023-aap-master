#ifndef CREATE_LINE_HPP
#define CREATE_LINE_HPP
#include <cstddef>
#include <cstring>

namespace psarev
{
  size_t createTaskLine(char* userLine, const char* presetLine, size_t userLen, size_t presetLen, char*& resLine);
};
#endif
