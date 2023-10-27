#include <iostream>
#include "count_count.hpp"
#include <limits>
using namespace::kovshikov;
int main()
{
  size_t num = 0;
  size_t count = 0;
  size_t max_count = 0;
  try
  {
    do
    {
      std::cin >> num;
      if (!std::cin)
      {
        throw std::invalid_argument("Incorrect input\n");
      }
      else
      {
        if (num != 0)
        {
          count = count_count(num, count);
          max_count = (max_count > count ? max_count : count);
        }
      }
    }
    while (num && std::cin);
  }
  catch (std::invalid_argument const& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::cout << max_count << "\n";
  return 0;
}
