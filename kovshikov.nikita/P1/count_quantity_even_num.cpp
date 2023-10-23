#include "count_quantity_even_num.hpp"
int count_quantity_even_num(int num, int quantity)
{
  if (num % 2 == 0)
  {
    quantity += 1;
  }
  else
  {
    quantity = 0;
  }
  return quantity;
}
