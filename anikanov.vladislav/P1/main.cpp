#include <iostream>
#include <limits>

int main()
{
  const long long max_count = std::numeric_limits<long long>::max();
  long long min_member = max_count;
  long long count, number;
  try {
    if (!(std::cin >> number)) throw std::logic_error("Wrong input");
    while (number != 0) {
      if (number == min_member && count < max_count) ++count;
      if (number == min_member && count == max_count) throw std::logic_error("To much minimal numbers");
      if (number < min_member) {
        min_member = number;
        count = 1;
      }
      if (!(std::cin >> number)) throw std::logic_error("Wrong input");
    }
  } catch (std::logic_error const &error) {
    std::cout << error.what() << "\n";
    return 2;
  }
  std::cout << count << "\n";
}
