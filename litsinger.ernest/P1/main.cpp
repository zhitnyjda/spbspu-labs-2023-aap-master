#include <iostream>
#include <limits>
#include <cmath>
#include <exception>

int main()
{
  int k = 0;
  int mx = 0;
  int n;
  std::cin >> n;
  if (n != static_cast<int>(n))
  {
    std::cout << "Input error\n";
    return 1;
  }
  if (std::cin.fail())
  {
    std::cout << "Input error\n";
    return 1;
  }
  if (n == 0)
  {
    std::cout << "Short sequence\n";
    return 2;
  }
  k = 1;
  mx = n;
  while (n != 0)
  {
    std::cin >> n;
    if (n > mx)
    {
      mx = n;
      k = 1;
    }
    if (n == mx)
    {
      k += 1;
    }
    if (n != static_cast<int>(n))
    {
      std::cout << "Input error\n";
      return 1;
    }
    if (std::cin.fail())
    {
      std::cout << "Input error\n";
      return 1;
    }
  }
  std::cout << k;
  return 0;
}   
