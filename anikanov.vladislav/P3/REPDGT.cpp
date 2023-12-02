#include "REPDGT.h"
#include <cstring>
#include <cctype>
#include <iostream>

int hasDuplicateDigits(const char *str)
{
  int entrance[10] = {0};
  for (int i = 0; i < strlen(str); ++i) {
    if (std::isdigit(str[i])){
      entrance[str[i] - '0']++;
    }
  }
  int max_count = 0;
  for (int i : entrance) {
    max_count = std::max(max_count, i);
  }
  return max_count;
}
