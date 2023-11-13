#include <iostream>
#include "FindingSubMax.hpp"

int main()
{
  using namespace khomichenko;
  FindingSubMax FindingSubMax;
  int num = 0;
  std::cin>>num;
  while ((std::cin) and (num !=0))
  {
    FindingSubMax(num);
    std::cin >> num;
  };
  if (!std::cin) {
    std::cerr<< "not a sequence\n";
    return 1;
  }
  else
  {
    try
    {
      std::cout<< FindingSubMax() << "\n";
      return 0;
    }
    catch (const std:: exception&e)
    {
      std::cerr<<e.what() << "\n";
      return 2;
    }
   }
};

