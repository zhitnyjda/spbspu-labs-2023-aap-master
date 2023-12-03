#include "matrix.hpp"
#include <fstream>
#include <iostream>

likhachev::Point::Point():
  x(0),
  y(0)
{}

likhachev::Point::Point(int newX, int newY):
  x(newX),
  y(newY)
{}

likhachev::Point& likhachev::Point::operator+=(const Point& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

void likhachev::inputMatrixFromFile(Point size, std::ifstream& inStream, int* values)
{
  for(int i = 0; i < size.x * size.y; i++) {
    inStream >> values[i];
    if (!inStream) {
      throw std::runtime_error("Error reading the matrix from the file.\n");
    }
  }
}

void likhachev::outputMatrixToFile(Point size, std::ofstream& outStream, int* values)
{
  outStream << size.x << " " << size.y << " ";
  for(int i = 0; i < size.x * size.y; i++) {
    outStream << values[i] << " ";
    if (!outStream) {
      throw std::runtime_error("Error writing the matrix to the file.\n");
    }
  }

  outStream << "\n";
}

int likhachev::countNonRepeatColumns(Point size, int* values)
{
  int totalCount = size.x;

  for( int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y - 1; j++) {
      if (values[size.x * j + i] == values[size.x * (j + 1) + i]) {
        totalCount--;
        break;
      }
    }
  }

  return totalCount;
}

void likhachev::changeMatrixWithSpiral(Point size, int* values)
{
  Point direction(1, 0);
  Point position(-1, 0);
  Point submatrixSize(size.x, size.y);
  int counter = 1;
  int steps = 0;
  while (submatrixSize.x > 0 && submatrixSize.y > 0) {
    if (direction.x % 2) {
      steps = submatrixSize.x;
      submatrixSize.y--;
    } else {
      steps = submatrixSize.y;
      submatrixSize.x--;
    }

    for(int j = 0; j < steps; j++) {
      position.x += direction.x % 2;
      position.y += direction.y % 2;
      values[position.x + position.y * size.x] += counter;
      counter++;
    }

    direction.x == 2 ? direction.x = -1 : direction.x++;
    direction.y == 2 ? direction.y = -1 : direction.y++;
  }
}


void likhachev::coutMatrix(Point size, int* values) {
  for(int i = 0; i < size.x * size.y; i++) { // Lavran [ToDo] : Удалить
    if(values[i] < 10) {
      std::cout << "0";
    }
    std::cout << values[i] << " ";
    if((i + 1) % size.x == 0) {
      std::cout << "\n";
    }
  }
}

