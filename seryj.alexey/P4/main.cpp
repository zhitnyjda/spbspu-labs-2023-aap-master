#include <iostream>
#include <fstream>
#include "Funcs.hpp"
int main(int args, const char* argv[])
{
  int n = 0;
  try
  {
    n = std::stoi(argv[1], nullptr, 10);
    if(argv[1][1])
    {
      std::cerr << "First argument is wrong\n";
      return 1;
    }
  }
  catch (std::logic_error const& e)
  {
    std::cerr << "First argument is not a number\n";
    return 1;
  }
  if (args != 4 || !(n == 2 || n == 1))
  {
   std::cerr << "Invalid arguments\n";
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
  int static_values [max_size] = { 0 };
  int * values = (n == 1) ? static_values : new int[to_read];
  size_t result = seryj::fillArray((n==1) ? max_size : to_read, to_read, input, values);
  if (result != to_read)
  {
    std::cerr << "Could only read " << result << " numbers. I needed " << to_read << "\n";
    if(n == 2)
      delete[] values;
    return 1;
  }
  seryj::printAvgOfNeigbours(line, column, output, values);
  if(n == 2)
    delete[] values;
  return 0;
}
