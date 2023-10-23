#include <iostream>
#include "count_quantity_even_num.hpp"
int main()
{
  int num = 0;
  int quantity = 0;
  int max_quantity = 0;
  std::cin >> num;
  while (true)
  {
    if (!std::cin)
    {
      std::cout << "error\n";
      return 1;
    }
    else if (num == 0)
    {
      std::cout << max_quantity << "\n";
      return 0;
    }
    else
    {
      quantity = count_quantity_even_num(num, quantity);
      if (quantity >= max_quantity)
      {
        max_quantity = quantity;
      }
      std::cin >> num;
    }
  }
  return 0;
}
