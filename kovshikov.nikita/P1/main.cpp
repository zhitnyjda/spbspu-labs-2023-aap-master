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
		if (!std::cin)    //проверка что на ввод подается целое число и его размеры умещаются в диапазон int
		{
			std::cout << "error";
			return 1;     //в случае неверного введения программа возвращает 1
		}
		else if (num == 0)
		{
			std::cout << max_quantity << "\n";
			return 0;
		}
		else
		{
			quantity = count_quantity_even_num(num, quantity);
			if (quantity >= max_quantity)  // если текущаю последовательность больше максимальной 
			{
				max_quantity = quantity;  // то максимальная принимает значение текущей
			}
			std::cin >> num;
		}
	}
	return 0;
}
