#include "divisibility.cpp"
#include <iostream>
#include <stdexcept>
#include <limits>

int main()
{
  kaseev::divisibility divisibility;
  try {
    int firstNum = 0, secondNum = 0;
    if (!(std::cin >> firstNum) || firstNum == 0)
    {
      throw std::logic_error("Wrong input");
    }
    if (!(std::cin >> secondNum))
    {
      throw std::logic_error("Wrong input");
    }
    if (firstNum == 0 || secondNum == 0)
    {
      throw std::logic_error("Not enough elements");
    }
    int ans;
    ans = divisibility(firstNum, secondNum);
    const int max_count = (std::numeric_limits<int>::max());
    if (ans > max_count)
    {
      throw std::overflow_error("Too many numbers");
    }
    divisibility(ans);
    return 0;
  }
  catch (const std::logic_error &error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }
}
