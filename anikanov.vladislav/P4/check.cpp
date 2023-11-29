#include <cctype>
#include <cstring>
#include "check.h"

bool isNumber(const char *str)
{
  char c = 0;
  for (size_t i = 0; i < strlen(str); ++i) {
    c = str[i];
    if (!std::isdigit(c)) {
      return false;
    }
  }
  return true;
}
