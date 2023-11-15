#include <iostream>
#include "findingCount.hpp"
int main()
{
  size_t value = 0;
  using namespace jirkov;
  FindingCount findingCount;
  size_t SeqCount = 0;
  std::cin >> value;
  while (value != 0)
  {
    ++SeqCount;
    findingCount(value);
    std::cin >> value;
  };
  if (!std::cin)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }
  else if (SeqCount < 2)
  {
    std::cerr << "Too short sequence\n";
    return 2;
  }
  else
  {
    std::cout << findingCount() << '\n';
    return 0;
  }
}
