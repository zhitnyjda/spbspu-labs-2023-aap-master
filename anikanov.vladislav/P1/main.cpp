#include <iostream>
#include "solve.hpp"

int main()
{
  long long answer;
  try {
    solving(answer);
  } catch (std::logic_error const &error) {
    std::cout << error.what() << "\n";
    return 2;
  }
  std::cout << answer << "\n";
}
