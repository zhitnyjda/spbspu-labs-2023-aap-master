#include <iostream>
#include "bool_foo.cpp"

int main()
{
  int prev, current, next;
  int count = 0;
  std::cin >> prev;
  try
  {
    while (std::cin >> current && current != 0)
    {
      std::cin >> next;
      if (bool_foo(prev, current, next))
      {
        count++;
      }
      prev = current;
    }
  } catch (std::exception& e) {
    std::cout << "Произошла ошибка при вводе данных: " << e.what() << std::endl;
    return 1;
  }
  std::cout << "Количество элементов: " << count << std::endl;
  return 1;
}
