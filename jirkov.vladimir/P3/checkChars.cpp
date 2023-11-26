#include <iostream>
#include <string>
#include "checkChars.hpp"
int checkChars(const std::string& input) {
  int result = 0;
  for (size_t i = 0; i < input.length() - 1; i++) {
    if (input[i] == input[i + 1]) {
      result = 1;
      break;
    }
  }
  return result;
}
