#include <iostream>
#include "findingCount.hpp"
int main()
{
  using namespace jirkov;
  FindingCount findingCount;
  size_t seqCount = 0;
  size_t value = 0;
  std::cin >> value;
  while (value != 0)
  {
    ++seqCount;
    findingCount(value);
    std::cin >> value;
  };
  if (!std::cin)
  {
    std::cerr << "Wrong Input\n";
    return 1;
  }
  else if (seqCount < 2)
  {
    std::cerr<< "too short sequence\n";
    return 2;
  }
  else
  {
    std::cout << findingCount() << '\n';
    return 0;
  }
}
