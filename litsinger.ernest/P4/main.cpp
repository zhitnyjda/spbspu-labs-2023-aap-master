#include <iostream>
#include <fstream>
#include "function.hpp"

using namespace litsinger;
int main(int args, const char* argv[])
{
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  try
  {
    int task = litsinger::fillArguments(args, argv);
    if (task == 1)
    {
      size_t line = 0;
      size_t column = 0;
      std::ifstream input(argv[2]);
      if (!input.is_open())
      {
        std::cerr << "Error\n";
        return 1;
      }
      input >> line >> column;
      int static_array[10000] = {0};
      for (size_t i = 0; i < (line * column); i++)
      {
        input >> static_array[i];
      }
      if (!output.is_open())
      {
        std::cerr << "Can not open output file";
        return 1;
      }
      output << MaximalSum(static_array, line, column);
    }
    else if (task == 2)
    {
      size_t line = 0;
      size_t column = 0;
      input >> line >> column;
      int * dynamic_array = new int[line * column];
      for (size_t i = 0; i < (line * column); i++)
      {
        input >> dynamic_array[i];
      }
      output << MaximalSum(dynamic_array, line, column);
      if (!output.is_open())
      {
        std::cerr << "Can not open output file";
      }
      delete[] dynamic_array;
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
