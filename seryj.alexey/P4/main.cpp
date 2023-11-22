#include "Funcs.hpp"
#include <iostream>
using namespace seryj;
int main(int args, const char* argv[])
{
  try
  {
    if (args > 4)
      throw (std::invalid_argument("Too much arguments"));
    if (args < 4)
      throw (std::invalid_argument("Not enough elements"));
    int n = std::strtoll(argv[1], nullptr, 10);
    if (n < 1 || n>2)
      throw(std::invalid_argument("Invalid argument"));
    int task = 1;/*seryj::fillArguments(args, argv);*/
    Matrix matrix;
    matrix.initMatrix(argv[2], argv[3]);
    int to_read = matrix.line * matrix.column;
    if (task == 1)
    {
      const size_t max_size = 10000;
      int static_array[max_size] = { 0 };
      matrix.initArray(static_array);
      int result = matrix.fillArray(max_size, to_read );
      if (result != to_read)
      {
        std::cerr << "Could only read " << result << " numbers. I needed " << to_read;
        return 1;
      }
      matrix.printAvgOfNeigbours();
    }
    else if (task == 2)
    {
      int* dynamic_array = new int[matrix.line * matrix.column];
      matrix.initArray(dynamic_array);
      try
      {
        int result = matrix.fillArray(to_read, to_read);
        if (result != to_read)
        {
          std::cerr << "Could only read " << result << " numbers. I needed "<<to_read;
          return 1;
        }
        matrix.printAvgOfNeigbours();
        delete[] dynamic_array;
      }
      catch (std::logic_error const & e)
      {
        std::cerr << e.what();
        delete[] dynamic_array;
        return 2;
      }
    }
  }
  catch (std::invalid_argument const & e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (std::logic_error const & e)
  {
    std::cerr << e.what();
    return 2;
  }
}
