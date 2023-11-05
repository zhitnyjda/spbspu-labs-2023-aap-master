#include <iostream>
#include "count_count.hpp"
#include <limits>
using namespace::kovshikov;
int main()
{
  size_t num = 0;
  size_t max = 0;
  try
  {
    Counter sequenceCounter;
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
          sequenceCounter(num);
          max = sequenceCounter();
        }
      }
    }
    while (num);
  }
  catch (std::invalid_argument const& e1)
  {
    std::cout << e1.what() << "\n";
    return 1;
  }
  catch (std::logic_error const& e2)
  {
    std::cout << e2.what() << "\n";
    return 1;
  }
  std::cout << max << "\n";
  return 0;
}
