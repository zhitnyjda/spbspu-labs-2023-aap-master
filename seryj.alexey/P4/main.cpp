#include <iostream>
#include "Funcs.hpp"
int main(int args, const char* argv[])
{
  int n = std::stoi(argv[1], nullptr, 10);
  if (args != 4 || !(n == 2 || n == 1))
  {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  int * pointer = nullptr;
  try
  {
    using namespace seryj;
    Matrix matrix;
    size_t to_read = matrix.initMatrix(argv[2], argv[3]);
    const size_t max_size = 10000;
    int static_array[max_size] = { 0 };
    int* dynamic_array = new int[to_read];
    pointer = (n == 1) ? static_array : dynamic_array;
    matrix.initArray(pointer);
    size_t result = matrix.fillArray((n==1) ? max_size : to_read, to_read);
    if (result != to_read)
    {
      std::cerr << "Could only read " << result << " numbers. I needed " << to_read << "\n";
      if(n == 2)
        delete[] pointer;
      return 1;
    }
    matrix.printAvgOfNeigbours();
    if(n == 2)
      delete[] pointer;
    return 0;
  }
  catch (std::logic_error const & e)
  {
    std::cerr << e.what();
    if(n == 2)
      delete[] pointer;
    return 2;
  }
}
