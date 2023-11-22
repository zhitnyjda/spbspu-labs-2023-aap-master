#include <fstream>
#include <cmath>
#include "Funcs.hpp"
namespace seryj
{
  size_t readSizeT(std::ifstream input)
  {
    size_t val = 0;
    if (!input.is_open())
      throw std::invalid_argument("Cant open input.txt");
    if (!input)
      throw std::logic_error("Input error");
    input >> val;
    return val;
  }
  void Matrix::initMatrix(const char* inp_file, const char* out_file)
  {
    input.open(inp_file);
    output.open(out_file);
    input >> line;
    input >> column;
  }
  void Matrix::initArray(int* arr)
  {
    values = arr;
  }
  int Matrix::fillArray(size_t max_size, size_t to_read)
  {
    for (size_t i = 0; i < std::min(to_read, max_size); ++i)
    {
      if (!input)
        return i;
      input >> *(values+i);
    }
    return std::min(to_read, max_size);
  }
  void Matrix::printAvgOfNeigbours()
  {
    if (output.is_open())
    {
      output << line << " ";
      output << column << " ";
      for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
          output << findAverageOfNeighbours(i, j) << " ";
        }
    }
    else throw (std::invalid_argument("Cant open output file"));
  }
  double Matrix::findAverageOfNeighbours(int curr_line, int curr_column) const
  {
    int count = 0;
    double sum = 0;
    size_t max_line = line;
    size_t max_column = column;
    for (int i = curr_line - 1; i <= curr_line + 1; i++)
      for (int j = curr_column - 1; j <= curr_column + 1; j++)
      {
        if (j >= 0 && j < max_column && i >= 0 && i < max_line)
        {
          sum += *(values + i * max_line + j);
          count++;
        }
      }
    count--;
    sum -= *(values + curr_line * max_line + curr_column);
    return round(sum / count * 10) / 10;
  }
}
