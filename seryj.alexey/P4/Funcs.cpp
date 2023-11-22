#include <fstream>
#include <cmath>
#include "Funcs.hpp"
namespace seryj
{
  size_t Matrix::initMatrix(const char* inp_file, const char* out_file)
  {
    input.open(inp_file);
    output.open(out_file);
    if(!input.is_open())
      throw std::invalid_argument("Cant open input file\n");
    if(!output.is_open())
      throw std::invalid_argument("Cant open output file\n");
    if(!(input >> line) || !(input >> column))
      throw std::logic_error("Wrong sizes\n");
    return line*column;
  }
  void Matrix::initArray(int* arr)
  {
    values = arr;
  }
  int Matrix::fillArray(size_t max_size, size_t to_read)
  {
    for (size_t i = 0; i < std::min(to_read, max_size); ++i)
    {
      if (!(input >> *(values + i)))
        return i;
    }
    return std::min(to_read, max_size);
  }
  void Matrix::printAvgOfNeigbours()
  {
    output << line << " ";
    output << column << " ";
    for (size_t i = 0; i < line; i++)
      for (size_t j = 0; j < column; j++)
      {
        output << findAverageOfNeighbours(i, j) << " ";
      }
  }
  double Matrix::findAverageOfNeighbours(size_t curr_line, size_t curr_column) const
  {
    int count = 0;
    double sum = 0;
    size_t max_line = line;
    size_t max_column = column;
    for (size_t i = curr_line; i <= curr_line + 2; i++)
      for (size_t j = curr_column; j <= curr_column + 2; j++)
      {
        if (j > 0 && j <= max_column && i > 0 && i <= max_line)
        {
          sum += *(values + (i-1) * max_line + j - 1);
          count++;
        }
      }
    count--;
    sum -= *(values + curr_line * max_line + curr_column);
    return round(sum / count * 10) / 10;
  }
}
