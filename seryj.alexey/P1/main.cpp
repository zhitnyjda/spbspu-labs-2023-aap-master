#include <iostream>
#include <cmath>
#include "EQL-SEQ.hpp"

int main()
{
  int count = 1;
  int max_count = 0;
  int last_value = 0;
  int current_value = 0;
  std::cin >> last_value;
  while (last_value && std::cin)
  {
    std::cin >> current_value;
    eqlSeq(last_value, current_value,count,max_count);
  }
  if (!std::cin)
  {
    std::cout << "Input Error" << "\n";
    return 1;
  }
  std::cout << "Result: " << max_count << "\n";
  return 0;
}
