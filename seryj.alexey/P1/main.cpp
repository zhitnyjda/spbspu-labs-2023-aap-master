#include <iostream>
#include "isEqual.hpp"
#include "maxint.hpp"

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
    count = isEqual(last_value, current_value) ? count + 1 : 1;
    max_count = maxInt(max_count, count);
    last_value = current_value;
  }
  if (!std::cin)
  {
    std::cout << "Input Error" << "\n";
    return 1;
  }
  std::cout << "Result: " << max_count << "\n";
  return 0;
}
