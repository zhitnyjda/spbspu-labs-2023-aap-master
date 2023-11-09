// #include "functions.hpp"
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  try
  {
    // checking params
    if (argc != 4)
    {
      throw std::invalid_argument("wrong arguments. Programm takes 3 positional");
    }
    //initing params
    try
    {
      int num = std::stoll(argv[1]);
    }
    catch(const std::invalid_argument& e)
    {
      std::cerr << "can't interpret first argument as integer\n";
    }

    std::size_t cols = 0, rows = 0;

    // reading matrix from file
    std::ifstream inputFile(argv[2]);
    inputFile >> rows, cols;

    inputFile.close();

    // parsing matrix
    return 0;
  }
  catch(const std::logic_error& logic_e)
  {
    std::cerr << logic_e.what();
    return 1;
  }
  catch(...)
  {
    std::cerr << "Some error occured\n";
  }
}
