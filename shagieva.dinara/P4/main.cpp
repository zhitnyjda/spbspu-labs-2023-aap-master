#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of input parameters.\n";
    return 1;
  }

  int task = 0;

  try
  {
    task = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot read the value of task.\n";
    return 1;
  }

  if (task != 1 && task != 2)
  {
    std::cerr << "Task does not exist.\n";
    return 1;
  }

  std::ifstream input;
  input.open(argv[2]);

  std::ofstream output;
  output.open(argv[3]);

  using namespace shagieva;
  Matrix matrix;

  input >> matrix.numberOfLines;
  input >> matrix.numberOfColumns;

  if (!input)
  {
    std::cerr << "Cannot read matrix data";
    return 2;
  }

  int result = 0;

  try
  {
    if (task == 1)
    {
      int staticArray[10000] = {0};
      matrix.values = staticArray;
      matrix.read(input);
      result = matrix.findMaxColumn();
    }

    if (task == 2)
    {
      int * dynamicArray = new int[matrix.numberOfLines * matrix.numberOfColumns];
      matrix.values = dynamicArray;
      matrix.read(input);
      result = matrix.findMaxColumn();
      delete[] dynamicArray;
    }
    output << result;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  return 0;
}

