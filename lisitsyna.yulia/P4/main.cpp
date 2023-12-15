#include <iostream>
#include <fstream>
#include <string>
#include "input_ar.hpp"
#include "minS.hpp"

using namespace lisitsyna;
int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrectly entered data" << "\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Please enter a valid value" << "\n";
    return 1;
  }
  if (num > 2 || num <= 0)
  {
    std::cerr << "Incorrect value" << "\n";
    return 2;
  }
  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Cannot read the file" << "\n";
    return 2;
  }
  if (input.eof())
  {
    std::cerr << "File is empty" << "\n";
    return 2;
  }
  principal drive;
  int* values;
  if (num == 1)
  {
    int static_[10000] = { 0 };
    values = static_;
    try
    {
      int kolvo = matrix.fl_ar(input, values, rows * cols);
      if (kolvo != rows * cols)
      {
        std::cerr << "Not correct" << "\n";
        return 2;
      }
      outputFile << principal.minsum(values, rows, cols);
      return 0;
      }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what();
      return 2;
    }
  }
  if (num == 2)
  {
  int* dinamo_ = new int[rows * cols];
  values = dinamo_;
  try
  {
    drive.arraay(rows, cols, input, values);
    delete[] dinamo_;
  }
  catch (std::logic_error const& e)
  {
    std::cerr << e.what();
    delete[] dinamo_;
    return 2;
  }
}
