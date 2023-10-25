#include <iostream>
#include <exception>
#include <typeinfo>
#include <limits>

int CounterAfterMaximum(int &f_num, int &f_max_num, int &f_counter, long &f_global_counter, int &f_minus, int &f_plus)
{
  const int f_max_int = std::numeric_limits< int >::max();
  int temp = f_num;
  while (temp != 0)
  {
    std::cin >> temp;
    if (std::cin.fail())
    {
      if ((temp % 10 != 0) && (typeid(temp % 10) == typeid(int)))
        throw std::overflow_error("Integer overflow");
      else
        throw std::invalid_argument("Wrong data type");
      std::cin.clear();
    }
    else
    {
      if (f_global_counter > f_max_int)
        throw std::overflow_error("Exceeded the maximum number of sequence elements");
      (temp > f_max_num) ? (f_max_num = temp, f_counter = 0) : (f_counter += 1);
      (temp < 0) ? (f_minus += 1) : (f_plus += 1);
      f_global_counter += 1;
    }
  }
  if (f_global_counter == 0)
    throw std::logic_error("Sequence elements are missing");
  if (((f_minus == 0) || (f_plus == 0)) && (f_global_counter > 1))
    throw std::overflow_error("The sequence includes numbers of the same sign");
  return f_counter;
}
