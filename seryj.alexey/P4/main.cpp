#include <iostream>
#include "Funcs.hpp"
int main(int args, const char* argv[])
{
  try
  {
    using namespace seryj;
    if (args > 4)
      throw (std::invalid_argument("Too much arguments"));
    if (args < 4)
      throw (std::invalid_argument("Not enough arguments"));
     int n = std::strtoll(argv[1], nullptr, 10);
    if (n < 1 || n>2)
      throw(std::invalid_argument("Invalid argument"));
    Matrix matrix;
    int to_read = matrix.initMatrix(argv[2], argv[3]);
    if (n == 1)
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
    else
    {
      int* dynamic_array = new int[to_read];
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
