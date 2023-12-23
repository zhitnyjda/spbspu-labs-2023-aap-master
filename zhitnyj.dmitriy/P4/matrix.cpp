#include "matrix.h"
#include <fstream>
#include <sstream>

Matrix::Matrix() : rows(0), cols(0), data(nullptr)
{
}

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols)
{
  allocateMemory();
}

Matrix::~Matrix()
{
  freeMemory();
}

void Matrix::allocateMemory()
{
  data = new int* [rows];
  for (size_t i = 0; i < rows; ++i)
  {
    data[i] = new int[cols];
  }
}

void Matrix::freeMemory()
{
  if (data != nullptr)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] data[i];
    }
    delete[] data;
    data = nullptr;
  }
}

void Matrix::loadFromFile(const std::string& filename)
{
  std::ifstream file(filename);

  if (!file)
  {
    throw std::logic_error("No file!");
  }

  if (!(file >> rows >> cols))
  {
    throw std::length_error("No data in file!");
  }

  freeMemory();
  allocateMemory();

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!(file >> data[i][j]))
      {
        throw std::length_error("Invalid input!");
      }
    }
  }

  if (file.get() && rows != 0)
  {
    throw std::length_error("Invalid input!");
  }
}

void Matrix::processLFT()
{
  if (!data || rows <= 0 || cols <= 0) return;

  size_t decrement = 1;
  size_t i = rows - 1;
  size_t j = 0;

  size_t directions[][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }}; // up, right, down, left
  size_t dir = 0;
  int** visited = new int* [rows];

  for (size_t k = 0; k < rows; ++k)
  {
    visited[k] = new int[cols]();
  }

  for (int processed = 0; processed < rows * cols; ++processed)
  {
    data[i][j] -= decrement;
    visited[i][j] = 1;
    decrement++;

    size_t next_i = i + directions[dir][0];
    size_t next_j = j + directions[dir][1];

    if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols || visited[next_i][next_j])
    {
      dir = (dir + 1) % 4;
      next_i = i + directions[dir][0];
      next_j = j + directions[dir][1];
    }

    i = next_i;
    j = next_j;
  }

  for (size_t k = 0; k < rows; ++k)
  {
    delete[] visited[k];
  }
  delete[] visited;
}

size_t Matrix::processMAX()
{
  size_t max_sum = 0;

  for (size_t start_row = 1; start_row < rows; ++start_row)
  {
    size_t sum_diag = 0;
    for (size_t i = 0; start_row + i < rows && i < cols; ++i)
    {
      sum_diag += data[start_row + i][i];
    }
    max_sum = std::max(max_sum, sum_diag);
  }

  for (size_t start_col = 1; start_col < cols; ++start_col)
  {
    size_t sum_diag = 0;
    for (size_t i = 0; i < rows && start_col + i < cols; ++i)
    {
      sum_diag += data[i][start_col + i];
    }
    max_sum = std::max(max_sum, sum_diag);
  }

  return max_sum;
}

void Matrix::saveToFile(const std::string& filename)
{
  std::ofstream file(filename);

  file << processMAX() << std::endl;

  processLFT();

  file << rows << " " << cols << " ";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      file << data[i][j] << " ";
    }
  }
}