#include <iostream>
#include "functions.hpp"
#include "dividing_counter.hpp"

int main()
{
  try
  {
    miheev::DevidingCounter dividing_counter(miheev::getNumberFromCin());
    dividing_counter.checkFirstPrevious();
    while(dividing_counter.getPrevious() != 0)
    {
      dividing_counter(miheev::getNumberFromCin());
    }
    if (!dividing_counter.getIfSeqLongEnough())
    {
      throw std::logic_error("Sequence is too short");
    }
    std::cout << dividing_counter.getCounter()<< '\n';
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

