#include <iostream>
#include "FindingSubMax.hpp"

int main()
{
  using namespace khomichenko;
  FindingSubMax FindingSubMax;
  size_t seqCount = 0;
  int num = 0;
  std::cin >> num;
  while (std::cin)
  {
    if (num == 0 and seqCount < 2)
    {
      std::cerr<< "too short sequence\n";
      return 2;
    }
    FindingSubMax(num);
    if (num == 0)
    {
      break;
    }
    ++seqCount;
    std::cin >> num;
  };
  if (!std::cin)
  {
  std::cerr << "not a sequence\n";
  return 1;
  }
  else
  {
    std::cout << FindingSubMax() << "\n";
    return 0;
  }
};
