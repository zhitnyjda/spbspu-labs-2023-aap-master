#include <iostream>
#include "even_count.hpp"

int main()
{
  size_t num = 0;
  using namespace::kovshikov;
  EvenCount sequenceEven;
  try
  {
    do
    {
      std::cin >> num;
      if (!std::cin)
      {
        throw std::logic_error("Incorrect input\n");
      }
      else
      {
        if (num != 0)
        {
          sequenceEven(num);
        }
      }
    }
    while (num);
  }
  catch (std::logic_error const& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::cout << sequenceEven() << "\n";
  return 0;
}
