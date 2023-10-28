#include <iostream> 

int main()
{
  int max = -1;
  int value = -1;
  int count = 0;
  while (value != 0)
  {
    std::cin >> value;
    if (value > max)
    {
      max = value;
      count = 0;
    }
    else if (value != 0)
    {
      count++;
    }
    else
    {
      std::cout << count << "\n";
      return 0;
    }
  }
  if (!std::cin)
  {
    std::cout << "anomaly\n";
    return 1;
  }
  if (value == 0)
  {
    std::cout << "short\n";
    return 2;
  }
}
