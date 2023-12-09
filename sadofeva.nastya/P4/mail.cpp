#include "iostream"
#include "fstream"
#include "string"
#include "matr.hpp"
using namespace sadofeva;

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
  int rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read file" << "\n";
    return 2;
  }
  //if (input.eof())
  //{
    //std::cerr << "File is empty" << "\n";
    //return 2;
  //}
  if (rows < 3 || cols < 0)
  {
    std::ofstream outp(argv[3]);
    outp << 0;
    return 0;
  }
  int* values;
  Matrix matrix;
  std::ofstream outputFile(argv[3]);
  if (!outputFile.is_open())
  {
    std::cerr << "Cannot open an ouput file" << "\n";
    return 2;
  }
  if (num == 1)
  {
    int static_ar[10000] = { 0 };
    values = static_ar;
    try
    {
      int kolvo = matrix.fl_ar(input, values,rows * cols);
      if (kolvo != rows * cols)
      {
        std::cerr << "Not" << "\n";
        return 2;
      }
      outputFile << matrix.locMax(values, rows, cols);
      return 0;
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what();
      return 2;
    }
  }
  if (num == 2)
  {
    int * dm_ar = new int[rows * cols];
    values = dm_ar;
    try
    {
      int kolvo = matrix.fl_ar(input, values,rows * cols);
      if (kolvo != rows * cols)
      {
        std::cerr << "Not correct" << "\n";
        delete[] dm_ar;
        return 2;
      }
      outputFile << matrix.locMax(values, rows, cols);
      delete[] dm_ar;
      return 0;
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what();
      delete[] dm_ar;
      return 2;
    }
  }
}
