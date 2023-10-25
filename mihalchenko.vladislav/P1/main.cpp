#include <iostream>
#include <exception>
#include <limits>
#include <typeinfo>
#include "Counter.hpp"

int main()
{
  const int min_int = std::numeric_limits< int >::min();
  int num = 1, counter = 0;
  int minus = 0, plus = 0, rez = 0;
  int max_num = min_int;
  long global_counter = -1;
  try
  {
    rez = CounterAfterMaximum(num, max_num, counter, global_counter, minus, plus);
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (std::overflow_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (std::logic_error const& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  std::cout << rez - 1;
  return 0;
}
