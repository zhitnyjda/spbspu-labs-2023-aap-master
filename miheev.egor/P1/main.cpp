#include <iostream>

void put_number_from_cin_to(int & variable)
{
  std::cin >> variable;
  if (!std::cin)
  {
    throw std::invalid_argument("Your input can't be interpret as a sequence of numbers\n");
  }
}

int main()
{
  try
  {
    int current_number = 0;
    int previous_number = 0;
    int count = -1;

    put_number_from_cin_to(current_number);

    while(current_number != 0)
    {
      previous_number = current_number;

      put_number_from_cin_to(current_number);

      if (current_number != 0)
      {
        count = (count == -1) ? 0 : count;
        if (current_number%previous_number == 0)
        {
          count++;
        }
      }
    }
    if (count == -1)
    {
      throw std::logic_error("Can't work with such sequence. Maybe it's too short?\n");
    }
    std::cout << count << '\n';
    return 0;
  }

  catch (const std::invalid_argument& error)
  {
    std::cout << error.what();
    return 1;
  }

  catch (const std::logic_error& error)
  {
    std::cout << error.what();
    return 2;
  }
}
