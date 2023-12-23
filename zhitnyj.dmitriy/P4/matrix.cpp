#include "matrix.h"
#include <fstream>
#include <sstream>
#include <iostream>

Matrix::Matrix() : rows(0), cols(0), data(nullptr)
{
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
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
  for (int i = 0; i < rows; ++i)
  {
    data[i] = new int[cols];
  }
}

void Matrix::freeMemory()
{
  if (data != nullptr)
  {
    for (int i = 0; i < rows; ++i)
    {
      delete[] data[i];
    }
    delete[] data;
    data = nullptr;
  }
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
  if(data)
  {
    freeMemory();
  }
  if (newRows != rows || newCols != cols)
  {
    rows = newRows;
    cols = newCols;
    allocateMemory();
  }

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

  char s = file.get();
  if ((s > 20) && rows != 0)
  {
    throw std::length_error("Invalid input!");
  }
}

void Matrix::processLFT()
{
  if (!data || rows <= 0 || cols <= 0) return;

  int decrement = 1;
  int i = rows - 1;
  int j = 0;

  int directions[][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }}; // up, right, down, left
  int dir = 0;
  int** visited = new int* [rows];

  for (int k = 0; k < rows; ++k)
  {
    visited[k] = new int[cols]();
  }

  for (int processed = 0; processed < rows * cols; ++processed)
  {
    data[i][j] -= decrement;
    visited[i][j] = true;
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
  int max_sum = 0;

  for (int start_row = 1; start_row < rows; ++start_row)
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

void Matrix::saveToFile(char* filename)
{
  std::ofstream file(filename);

  file << processMAX() << std::endl;

  processLFT();

  file << rows << " " << cols << " ";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      file << data[i][j] << " ";
    }
  }
  
  freeMemory();
}
