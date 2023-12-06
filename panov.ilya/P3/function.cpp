#include "function.hpp"
#include <cctype>
#include <cstring>

std::string removeVowels(const std::string& input) {
  if (input.empty()) {
    exit (1);
  }

  std::string result;

  for (char c : input) {
    if (!std::isalpha(c) || std::strchr("AOEIUYaoeiuy", c) == nullptr) {
      result += c;
    }
  }

  return result;
}
