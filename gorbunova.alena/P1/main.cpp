#include <iostream>

int main()
{
  int a, b, c;
  int count = 0;
  int pos = 0;
  std::cin >> a >> b >> c;
  pos += 3;
  while ((a != 0) && (b != 0) && (c != 0))
  {
    if (a + b == c)
    {
      count += 1;
      a = b;
      b = c;
      std::cin >> c;
      pos += 1;
    }
    else
    {
      a = b;
      b = c;
      std::cin >> c;
      pos += 1;
    }
  }
  if (pos > 3)
  {
    if ((a == 0) || (b == 0) || (c == 0))
    {
      std::cout << count << "\n";
      return 0;
    }
  }
  else
  {
    std::cout << "Expects error output" << "\n";
    return 2;
  }
}
