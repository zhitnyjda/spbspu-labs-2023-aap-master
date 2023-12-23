#include "matrix.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Matrix::Matrix() : rows(0), cols(0), data(nullptr)
{
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(nullptr)
{
  if (rows > 0 && cols > 0)
  {
    allocateMemory();
  }
}

Matrix::~Matrix()
{
  freeMemory();
}

void Matrix::allocateMemory()
{
  freeMemory();
  data = new int* [rows];
  for (int i = 0; i < rows; ++i)
  {
    data[i] = new int[cols]{ 0 };
  }
}

void Matrix::freeMemory()
{
  for (int i = 0; i < rows; ++i)
  {
    delete[] data[i];
  }
  delete[] data;
  data = nullptr;
}

void Matrix::loadFromFile(char* filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::logic_error("No file!");
  }

  int newRows, newCols;
  if (!(file >> newRows >> newCols))
  {
    throw std::length_error("Invalid data!");
  }

  if (newRows <= 0 || newCols <= 0 || newRows > 99 || newCols > 99)
  {
    throw std::length_error("Invalid data!");
  }

  rows = newRows;
  cols = newCols;
  allocateMemory();

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(file >> data[i][j]))
      {
        throw std::length_error("Invalid input!");
      }
    }
  }
  int s = file.get();
  if ((s > 20) && rows != 0)
  {
    if (data != nullptr)
    {
      freeMemory();
    }
    file.close();
    throw std::length_error("Invalid input!");
  }
  file.close();
}

void Matrix::processLFT()
{
  int decrement = 1;
  int i = rows - 1;
  int j = 0;

  int directions[][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
  int dir = 0;
  int** visited = new int* [rows];

  for (int k = 0; k < rows; ++k)
  {
    visited[k] = new int[cols]();
  }

  for (int processed = 0; processed < rows * cols; ++processed)
  {
    data[i][j] -= decrement;
    visited[i][j] = 1;
    decrement++;

    int next_i = i + directions[dir][0];
    int next_j = j + directions[dir][1];

    if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols || visited[next_i][next_j])
    {
      dir = (dir + 1) % 4;
      next_i = i + directions[dir][0];
      next_j = j + directions[dir][1];
    }

    i = next_i;
    j = next_j;
  }

  for (int k = 0; k < rows; ++k)
  {
    delete[] visited[k];
  }
  delete[] visited;
}

size_t Matrix::processMAX()
{
  int max_sum = INT_MIN;

  for (int start_row = 0; start_row < rows; ++start_row)
  {
    int sum_diag = 0;
    for (int i = 0; start_row + i < rows && i < cols; ++i)
    {
      sum_diag += data[start_row + i][i];
    }
    max_sum = std::max(max_sum, sum_diag);
  }

  for (int start_col = 1; start_col < cols; ++start_col)
  {
    int sum_diag = 0;
    for (int i = 0; i < rows && start_col + i < cols; ++i)
    {
      sum_diag += data[i][start_col + i];
    }
    max_sum = std::max(max_sum, sum_diag);
  }

  return max_sum;
}

void Matrix::saveToFile(const char* filename)
{
  std::ofstream file(filename);

  if (!file)
  {
    throw std::logic_error("Could not open file for writing!");
  }

  file << processMAX() << std::endl;

  processLFT();

  file << rows << " " << cols << std::endl;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      file << data[i][j] << " ";
    }
    file << std::endl;
  }
  file.close();
}
