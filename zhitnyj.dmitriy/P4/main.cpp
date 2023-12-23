#include "Matrix.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    throw std::logic_error("Not enough parameters!");
  }

  try
  {
    int num = std::stoi(argv[1]);
    std::string inputFilename = argv[2];
    std::string outputFilename = argv[3];

    Matrix matrix;
    if (num == 1)
    {
      matrix = Matrix(100, 100);
    }
    else if (num == 2)
    {
      matrix = Matrix();
    }
    else
    {
      throw std::overflow_error("First parameter is out of range");
    }

    matrix.loadFromFile(inputFilename);
    matrix.saveToFile(outputFilename);
  }
  catch (const std::length_error& err)
  {
    std::cerr << err.what() << std::endl;
    return 2;
  }
  catch (const std::invalid_argument& err)
  {
    std::cerr << "The first argument must be a number!" << std::endl;
    return 1;
  }
  catch (const std::logic_error& err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return 1;
  }
  catch (const std::exception& err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return 2;
  }

  return 0;
}
