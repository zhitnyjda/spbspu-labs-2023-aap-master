#include <iostream>
#include "function.hpp"

int main()
{
  int num = 0;
  int countmaximum = 0;
  try
  {
    std::cin >> num;
    countmaximum = maxCountNumbers(num);
  }
  catch (const std::invalid_argument & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  catch (const std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  std::cout << countmaximum << "\n";
  return 0;
}
