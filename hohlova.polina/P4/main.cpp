#include "inputArray.hpp"
#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
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
  char* dynamicm = nullptr;
  int num = std::strtoll(argv[1], std::addressof(dynamicm), 10);
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Cannot open file\n";
    return 2;
  }
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
    int staticm[1000] = { 0 };
    output << hohlovaa::countStrings(staticm, rows, cols);
  }
  else
  {
    int* dynamicm = new int[rows * cols];
    size_t toRead = hohlova::inputArray(input, dynamicm, rows * cols);
    if (toRead != static_cast<unsigned long long>(rows) * cols)
    {
      std::cerr << "Not all elements are read\n";
      delete[] dynamicm;
    }
    try
    {
      std::ofstream output(argv[3]);
      output << hohlovaa::countStrings(dynamicm, rows, cols);
    }
    catch (std::runtime_error const& e)
    {
      std::cerr << e.what() << "\n";
      if (num == 2)
      {
        delete[] dynamicm;
      }
      return 1;
    }
    if (num == 2)
    {
      delete[] dynamicm;
    }
  }
  return 0;
}
