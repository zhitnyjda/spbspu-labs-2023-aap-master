#include <iostream>
#include "function.hpp"

int main() {
  std::string input;
  std::getline(std::cin, input);
  try {
    std::string result = removeVowels(input);
    std::cout << result << std::endl;
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Error: Unable to allocate memory." << std::endl;
    return 1;
  }
  return 0;
}
