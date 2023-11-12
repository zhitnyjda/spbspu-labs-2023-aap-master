#include "defoult.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
namespace panov
{
  std::ifstream input;
  std::ofstream output;
  int fillsArguments(int args, const char* argv[])
  {
    if (args > 4)
      throw (std::invalid_argument("MuchArgument"));
    if (args < 4)
      throw (std::invalid_argument("NonEnophArguments"));
    input.open(argv[2]);
    output.open(argv[3]);
    int n = std::strtoll(argv[1], nullptr, 10);
    if (n < 1 || n > 2)
      throw(std::invalid_argument("InvalidArgument"));
    return n;
  }
  int read()
  {
    int val = 0;
    if (input.is_open() && input)
      input >> val;
    else if (!input.is_open())
      throw std::invalid_argument("CantOpenInput");
    if (!input)
      throw std::logic_error("InputError");
    return val;
  }
  void Matrix::ArrayThatFills()
  {
    int count = 0;
    while (input.good())
    {
      *(values + count) = read();
      count++;
    }
    if (count < line * column)
      throw std::logic_error("NotEughElements");
  }
  void Matrix::printAvgOfNeigbours()const
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
    else throw (std::invalid_argument("CantOpenOutputFile"));
    output.close();
  }
  void SetSides(int* ar, std::ifstream input)
  {
    int max_y;
    input >> max_y;
    int max_x;
    input >> max_x;
    int k = 0;
    int y = max_y;
    int x = 0;
    int min_x = 0;
    int min_y = 0;
    const int l = max_x;
    const int o = max_y;
    std::string directions = "up";
    while (k <= (l * o))
    {
      k++;
      input >> *(ar + x * l + y);
      *(ar + x * l + y) -= k;
      if (directions == "up")
      {
        y--;
        if (y == min_y)
        {
          min_y++;
          directions = "right";
        }
      }
      if (directions == "right")
      {
        x++;
        if (x == max_x)
        {
          max_x--;
          directions = "down";
        }
      }
      if (directions == "down")
      {
        y++;
        if (y == max_y)
        {
          max_y--;
          directions = "left";
        }
      }
      if (directions == "left")
      {
      x--;
      if (x == min_x)
      {
        min_x++;
        directions = "up";
      }
    }
  }
}