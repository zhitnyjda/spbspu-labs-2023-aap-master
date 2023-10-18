#include <iostream>

int main()
{
  int current_number = 0;
  int previous_number = 0;
  int count = 0;

  std::cin >> current_number;

  while(std::cin)
  {
    previous_number = current_number;
    if (previous_number == 0){
      std::cout << "Programm can't work with such sequence. Maybe it's too short?";
      return 2;
    }

    std::cin >> current_number;

    if (current_number == 0)
    {
      std::cout << count << '\n';
      return 0;
    }
    else if (current_number%previous_number == 0)
    {
      count++;
    }
  }
  std::cout << "Something you considered number sequence can't be interpret this way.\n Please, use numbers next time\n";
  return 1;
}
