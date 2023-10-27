#include <iostream>

int main()
{
  int a;
  std::cin >> a;
  if (!std::cin)
  {
    std::cout << "enter numbers\n";
    return 1;
  }
  if (a == 0)
  {
    std::cout << a << "\n";
    return 0;
  }
  int min = a;
  int count = 1;
  while ((std::cin) and (a != 0))
  {
    std::cin >> a;
    if (!std::cin)
    {
      std::cout << "enter numbers\n";
      return 1;
    }
    if ((a == min) and (a != 0))
    {
      count++;
    }
    else if ((a < min) and (a != 0))
    {
      min = a;
      count = 1;
    }
    else if (a == 0)
    {
      std::cout << count << "\n";
      return 0;
    }
  }
}
