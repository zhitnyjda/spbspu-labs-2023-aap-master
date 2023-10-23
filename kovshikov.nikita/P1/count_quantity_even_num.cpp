#include "count_quantity_even_num.hpp"
int count_quantity_even_num(int num, int quantity)
{
	if (num % 2 == 0)  // если число четное
	{
		quantity += 1;  // то увеличиваем текущую последовательность четных чисел на 1
	}
	else
	{
		quantity = 0;  // то обнуляем текущую последовательность
	}
	return quantity;
}
