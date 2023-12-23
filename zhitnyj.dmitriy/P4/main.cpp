#include "matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Not enough parameters!");
    }

    for (int c = 0; argv[1][c] != '\0'; c++)
    {
      if (!std::isdigit(argv[1][c]))
      {
        throw std::invalid_argument("First argument must be a number");
      }
    }
    int num = std::stoi(argv[1]);

    if (num == 1)
    {
      Matrix matrix = Matrix(10, 10, 1);
      matrix.loadFromFile(argv[2]);
      matrix.saveToFile(argv[3]);
    }
    else if (num == 2)
    {
      Matrix matrix = Matrix();
      matrix.loadFromFile(argv[2]);
      matrix.saveToFile(argv[3]);
    }
    else
    {
      throw std::overflow_error("First parameter is out of range");
    }
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
