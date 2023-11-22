#include <iostream>
#include "InputString.hpp"
#include "ExcludeSecString.hpp"

int main() {

  size_t first_size = 20;
  size_t second_size = 20;
  size_t add_size = 20;
  
  char * first_string = nullptr;
  first_string = inputString(std::cin, first_size, add_size);
  
  char * second_string = nullptr;
  second_string = inputString(std::cin, second_size, add_size);
  
  char * result_string = nullptr;
  result_string = ExcludeSecString(first_string, second_string, first_size, second_size);
  
  std::cout << result_string << "\n";
  
  delete [] first_string;
  delete [] result_string;
  
  return 0;
}
