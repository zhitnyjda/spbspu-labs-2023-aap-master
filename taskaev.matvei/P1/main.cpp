#include <iostream>

int main()
{
  int num = 0;
  int count = 1;
  int previousNum = 0;
  int max_count = 0;
  int countNum = 0;
  do
  {
    std::cin >> num;
    countNum += std::cin ? (num ? 1 : 0) : 0;
    if (previousNum == num) {
      count++;
    } else {
      if (count > max_count) {
        max_count = count;
        count = 1;
      }
    }
    previousNum = num;
  }
  while (num && std::cin);
  if (!std::cin) {
    std::cout << "Error occured.\n";
    return 1;
  }
  if (countNum < 2) {
    std::cout << "Error, short sequence.\n";
    return 2;
  }
  std::cout << "Maximum repeating numbers: " << max_count << "\n";
  return 0;
}
