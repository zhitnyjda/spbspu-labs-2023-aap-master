#include "function.hpp"
#include <cctype>

std::string removeVowels(const std::string& input) {
  std::string result;

  for (char c : input) {
    if (!std::isalpha(c) || !std::strchr("AOEIUYaoeiuy", c)) {
      result += c;
    }
  }

  return result;
}
