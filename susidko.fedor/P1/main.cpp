#include <iostream>

int main()
{ double a0 = 0;
  double a1 = 0;
  double a2 = 0;
  double a3 = 0;
  int c = 0;

  while (1)
  {
    std::cin >> a3;
    if (!std::cin)
    {
      std::cerr << "Ne posledovatel`nost`";
      return 1;
    }
    if (a3 == 0)
    {
      if (a0 == 0)
      {
        std::cerr << "Malo";
        return 2;
      }
      else
      {
        std::cout << c;
        return 0;
      }
    }
    if ((a3 == a1 + a2) && (a1 != 0))
    {
      c += 1;
    }
    a0 = a1;
    a1 = a2;
    a2 = a3;
  }
}
