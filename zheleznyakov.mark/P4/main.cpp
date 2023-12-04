#include <iostream>
#include <fstream>
#include "classes.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: wrong args count.\n";
    return 1;
  }
  int task = 0;
  try
  {
    task = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Error: Cannot read task ID: invalid argument.\n";
    return 1;
  }
  catch (const std::istream::failure &e)
  {
    std::cerr << "Error: Cannot read task ID: input error.\n";
    return 1;
  }
  if (task != 1 && task != 2)
  {
    std::cerr << "Error: I can't do that - this task ID is invalid.\n";
    return 1;
  }
  std::ifstream inputStream;
  inputStream.open(argv[2]);
  std::ofstream outputStream;
  outputStream.open(argv[3]);
  zheleznyakov::Matrix matrix;
  inputStream >> matrix.columns;
  inputStream >> matrix.rows;
  if (!inputStream)
  {
    std::cerr << "Error: Cannot read input.\n";
    return 2;
  }
  int result = 0;
  int * array = task == 2 ? new int[matrix.columns * matrix.rows] : new int[10000];
  try
  {
    matrix.values = array;
    matrix.read(inputStream);
    result = matrix.findMaxRow();
    delete[] array;
  }
  catch (const std::runtime_error &e)
  {
    delete[] array;
    std::cerr << e.what();
    return 2;
  }
  outputStream << result;
  return 0;
}
