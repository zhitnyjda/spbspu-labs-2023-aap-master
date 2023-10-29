#include <iostream>

int main()
{
  int a, b, c;
  int count = 0;
  std::cin >> a >> b >> c;
  while ((a != 0) && (b != 0) && (c != 0))
  {
    if (a + b == c)
    {
      count += 1;
      a = b;
      b = c;
      std::cin >> c;
    }
    else
    {
      a = b;
      b = c;
      std::cin >> c;
    }
  }
  if ((a == 0) || (b == 0) || (c == 0))
  {
    std::cout << count << "\n";
  }
  return 0;
}
