#include <iostream>
#include "functions.hpp"

int main()
{
  int answer = 0;
  try {
    answer = findSecondMax(std::cin);
  } catch (const std::exception & err) {
    std::cout << err.what() << std::endl;
    return 2;
  }
  std::cout << answer << std::endl;
  return 0;
}