#include "defoult.hpp"
#include <iostream>
using namespace panov;
int main(int args, const char* argv[])
{
  try
  {
    int task = panov::fillsArguments(args, argv);
    Matrix matrix;
    matrix.line = read();
    matrix.column = read();
    if (task == 1)
    {
      int static_array[10001] = { 0 };
      matrix.values = static_array;
      matrix.ArrayThatFills();
      matrix.printAvgOfNeigbours();
    }
    else if (task == 2)
    {
      int* dynamic_array = new int[matrix.line * matrix.column];
      matrix.values = dynamic_array;
      try
      {
        matrix.ArrayThatFills();
        matrix.printAvgOfNeigbours();
        delete[] dynamic_array;
      }
      catch (std::logic_error const& e)
      {
        std::cerr << e.what();
        delete[] dynamic_array;
        return 2;
      }
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (std::logic_error& e)
  {
    std::cerr << e.what();
    return 2;
  }
}