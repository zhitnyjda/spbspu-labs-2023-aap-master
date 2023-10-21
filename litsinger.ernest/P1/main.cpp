#include <iostream>
#include "maxelement.hpp"

int main()
{
  int k;
  int kk = 1;
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
    std::cout("Only int");
	return 1;
  }
  if (n > maxlim || n < minlim)
  {
	std::cout << "Overflow";
	return 1;
  }
  int mx;
  mx = n;
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
	  std::cout("Only int");
	  return 1;
	}
	if (n > maxlim || n < minlim)
	{
	  std::cout << "Overflow";
	  return 1;
	}
	kk = maxelement(int n, int k, int mx)
  }
  std::cout << kk;
  return 0;
}

