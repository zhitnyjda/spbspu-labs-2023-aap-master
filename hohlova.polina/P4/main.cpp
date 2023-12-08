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
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot open an input file\n";
    return 2;
  }
  if (num == 1 || num == 2)
  {
    std::ofstream output(argv[3]);
    if (rows != cols)
    {
      std::cerr << "Not a square\n";
    }
  }
  if (num == 1)
  {
    std::ofstream output(argv[3]);
    int staticm[1000] = { 0 };
    try
    {
      hohlova::inputArray(input, staticm, rows * cols);
    }
    catch (std::logic_error const& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    output << hohlovaa::countStrings(staticm, rows, cols);
  }
  else if (num == 2)
  {
    std::ofstream output(argv[3]);
    int* dynamicm = new int[rows * cols];
    size_t toRead = hohlova::inputArray(input, dynamicm, rows * cols);
    if (toRead != rows * cols)
    {
      delete[] dynamicm;
      std::cerr << "Not all elements are read\n";
      return 1;
    }
    try
    {
      hohlova::inputArray(input, dynamicm, rows * cols);
      std::ofstream output(argv[3]);
    }
    catch (std::logic_error const& e)
    {
      std::cerr << e.what() << "\n";
      delete[] dynamicm;
      return 2;
    }
    try
    {
      output << hohlovaa::countStrings(dynamicm, rows, cols);
    }
    catch (std::invalid_argument const& e)
    {
      delete[] dynamicm;
      std::cerr << e.what();
      return 0;
    }
    delete[] dynamicm;
  }
  else
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}

