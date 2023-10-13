#include <iostream>

int main()
{ 
  int vvod_chisla = 0;
  int count = 1;
  int b = 0;
  int max = 0;
  bool q = true;
  while (q == true)
  {
    std::cin >> vvod_chisla;
    if (vvod_chisla == 0)
    {
      q = false;
    }
    else
    {
      if (b == vvod_chisla) 
      {
        count += 1;
      }
      else
      {
        if (count > max)
        {
	  max = count;
	  count = 1;
	}
      }
      b = vvod_chisla;
    }
  }
  if (!std::cin)
  {
    std::cerr << "error\n";
    return 2;
  }
  std::cout << max << "\n";
  return 1;
}
