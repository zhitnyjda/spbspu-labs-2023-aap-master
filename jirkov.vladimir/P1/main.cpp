#include <iostream>
#include "findingCount.hpp"
using namespace jirkov;
int main()
{
  size_t prev = 0;
  size_t current = 0;
  size_t next = 0;
  size_t count = 0;
  try
  {
    FindingCount findingCount;
    std::cin >> prev;
    if (prev == 0 && std::cin)
    {
      throw std::logic_error("Sequence very short\n");
    }
    std::cin >> current;
    if (current == 0 && std::cin)
    {
      throw std::logic_error("Sequence very short\n");
    }
    do
    {
      std::cin >> next;
      if (!std::cin)
      {
        throw std::invalid_argument("Incorrect Input\n");
      }
      if (next == 0 && findingCount.lenghts < 3)
      {
        throw std::logic_error("Sequence very short\n");
      }
      if (next != 0)
      {
        findingCount(prev, current, next);
        count = findingCount();
        prev = current;
        current = next;
      }
    } while (next != 0);
  }
  catch (std::invalid_argument const& e1)
  {
    std::cout << e1.what() << '\n';
    return 1;
  }
  catch (std::logic_error const& e2)
  {
    std::cout << e2.what() << '\n';
    return 2;
  }
  std::cout << count << '\n';
  return 0;
}
