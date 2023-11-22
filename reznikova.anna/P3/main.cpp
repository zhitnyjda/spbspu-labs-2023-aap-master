#include <iostream>
#include "InputString.hpp"

int main() {

  size_t size = 20;
  size_t add_size = 20;
  char * string = nullptr;
  
  string = inputString(std::cin, size, add_size);
  
  std::cout << string << "\n";
  delete [] string;
  
  return 0;
}
