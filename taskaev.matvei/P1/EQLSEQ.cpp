#include <iostream>

int main()
{
  int a = 0;
  int count = 1;
  int b = 0;
  int max = 0;
  do
  {
    std::cin >> a;
    if (b == a) {
      count = count + 1;
    } else {
      if (count > max) {
        max = count;
        count = 1;
      }
    }
    b = a;
  }
  while (a && std::cin);
  if (!std::cin) {
    std::cout << "Error occured\n";
    return 1;
  }
  std::cout << max << "\n";
  return 0;
}
