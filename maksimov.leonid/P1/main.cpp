#include <iostream>
#include <execution>
#include "sequaence_counter.cpp"

int main()
{
  int a = 0;
  int b = 0;
  int c = 1;
  int count = 0;
  int counter = 0;
  std::cin.exceptions(std::cin.failbit);
  while (c != 0)
  {
    try
    {
      std::cin >> c;
      sequaence_counter(a, b, c, count, counter);
      a = b;
      b = c;
    }
    catch (const std::exception &)
    {
      return 1;
    }
  }
  std::cout << counter;
  return 0;
}
