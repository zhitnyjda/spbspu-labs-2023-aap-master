#include <iostream>
#include "FindingSubMax.hpp"

int main()
{
  using namespace khomichenko;
  FindingSubMax FindingSubMax;
  size_t seqCount = 0;
  size_t num = 0;
  std::cin >> num;
  while (std::cin)
  {
    ++seqCount;
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
