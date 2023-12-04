#include "inputArray.hpp"
#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdexcept>

int main(int argc, char** argv)
{ 
  using namespace hohlova;
  using namespace hohlovaa;
  if (argc != 4)
  {
    std::cerr << "Something wrong, problem with number of arguments\n";
    return 1;
  }
  int num = std::stoll(argv[1]);
  int staticm[1000] = { 0 };
  int* dynamicm = nullptr;
  try
  {
    int rows = 0;
    int cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read an input\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    if (num > 2 || num < 1)
    {
      std::cerr << "It can be only 1 or 2\n";
      return 2;
    }
    else if (num == 1)
    {
      output << hohlovaa::countStrings(staticm, rows, cols);
    }
    else
    {
      int* dynamicm = new int[rows * cols];
      size_t toRead = hohlova::inputArray(input, dynamicm, rows * cols);
      if (toRead != rows * cols)
      {
        std::cerr << "Not all elements are read\n";
        delete[] dynamicm;
      }
      std::ofstream output(argv[3]);
      if (!output)
      {
        std::cerr << "File not open\n";
        delete[] dynamicm;
        return 2;
      }
      output << hohlovaa::countStrings(dynamicm, rows, cols);
    }
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 2;
  }
  return 0;
}
