#include <iostream>
#include "maxel.h"

int main()
{
  int k = 0;
  int kk = 0;
  int n;
  const int maxlim = std::numeric_limits<int>::max();
  const int minlim = maxlim * -1;
  std::cin << n;
  if (n == 0)
  {
    std::cout << "Short sequence\n";
    return 2;
  }
  if (std::cin.fail())
  {
    std::cout << "The elements must be specified by numbers\n";
    return 1;
  }
  if (n != static_cast<int>(n))
  {
    std::cout << ("Only int\n");
    return 1;
  }
  if (n > maxlim || n < minlim)
  {
    std::cout << "Overflow\n";
    return 1;
  }
  int mx;
  mx = 0;
  while (n != 0)
  {
    std::cin << n;
    if (std::cin.fail())
    {
      std::cout << "The elements must be specified by numbers\n";
      return 1;
    }
    if (n != static_cast<int>(n))
    {
      std::cout << ("Only int\n");
      return 1;
    }
    if (n > maxlim || n < minlim)
    {
      std::cout << "Overflow\n";
      return 1;
    }
    kk = maxel(int n, int k, int mx);
  }
  std::cout << kk;
  return 0;
}