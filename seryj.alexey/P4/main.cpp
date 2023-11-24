#include <iostream>
#include <fstream>
#include "Funcs.hpp"
int main(int args, const char* argv[])
{
  int n = 0;
  try
  {
    char * task_pointer;
    n = std::stoi(argv[1], task_pointer, 10);
    if(*(task_pointer))
      throw std::logic_error("");
  }
  catch (std::logic_error const& e)
  {
    std::cerr << "First argument is wrong\n";
    return 1;
  }
  if (args != 4 || !(n == 2 || n == 1))
  {
   std::cerr << "Invalid arguments";
   return 1;
  }
  int line = 0;
  int column = 0;
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open() || !output.is_open()) {
    std::cerr << "Wrong path to file\n";
    return 1;
  }
  if (!(input >> line) || !(input >> column)) {
    std::cerr << "Wrong sizes\n";
    return 2;
  }
  size_t to_read = line * column;
  const size_t max_size = 10000;
  int static_array[max_size] = { 0 };
  int* dynamic_array = new int[to_read];
  int * pointer = (n == 1) ? static_array : dynamic_array;
  size_t result = seryj::fillArray((n==1) ? max_size : to_read, to_read, input, pointer);
  if (result != to_read)
  {
    std::cerr << "Could only read " << result << " numbers. I needed " << to_read << "\n";
    delete[] dynamic_array;
    return 1;
  }
  seryj::printAvgOfNeigbours(line, column, output, pointer);
  delete[] dynamic_array;
  return 0;
}
