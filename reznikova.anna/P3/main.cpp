#include <iostream>
#include "InputString.hpp"
#include "ExcludeSecString.hpp"

int main() {

  size_t first_size = 20;
  size_t second_size = 20;
  size_t add_size = 20;
  
  char * first_string = nullptr;
  try
  {
    first_string = inputString(std::cin, first_size, add_size);
  }
  catch (const std::exception & e)
  {
    delete [] first_string;
    std::cerr << e.what() << "\n";
    return 1;
  }
  
  char * second_string = nullptr;
  try
  {
    second_string = inputString(std::cin, second_size, add_size);
  }
  catch (const std::exception & e)
  {
    delete [] second_string;
    std::cerr << e.what() << "\n";
    return 1;
  }
  
  char * result_string = nullptr;
  result_string = ExcludeSecString(first_string, second_string, first_size, second_size);
  
  std::cout << result_string << "\n";
  
  delete [] first_string;
  delete [] second_string;
  delete [] result_string;
  
  return 0;
}
