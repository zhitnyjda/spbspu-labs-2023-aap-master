#include <iostream>
#include "functions.hpp"
#include "dividing_counter.hpp"

int main()
{
  try
  {
    miheev::DevidingCounter deviding_counter(miheev::get_number_from_cin());
    while(deviding_counter.previous != 0)
    {
      deviding_counter(miheev::get_number_from_cin());
    }
    if (!deviding_counter.seq_is_long_enough)
    {
      throw std::logic_error("Sequence is too short");
    }
    std::cout << deviding_counter.counter << '\n';
    return 0;
  }
  catch (const std::invalid_argument& error)
  {
    std::cout << error.what() << '\n';
    return 1;
  }
  catch (const std::domain_error& error)
  {
    std::cout << error.what() << '\n';
    return 2;
  }
  catch (const std::logic_error& error)
  {
    std::cout << error.what() << '\n';
    return 2;
  }
}

