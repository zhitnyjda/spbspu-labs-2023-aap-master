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

likhachev::Matrix::Matrix(char type, int mCols, int mRows)
{
  size.x = mCols;
  size.y = mRows;

  if (type == '1') {
    int array[10000] = { 0 };
    values = array;
  } else  if (type == '2') {
    int * array = new int[size.x * size.y];
    values = array;
  }
}

void likhachev::Matrix::inputFromFile(std::ifstream& inStream)
{
  for(int i = 0; i < size.x * size.y; i++) {
    inStream >> values[i];
  }
}

void likhachev::Matrix::outputToFile(std::ofstream& outStream)
{
  outStream << size.x << " " << size.y << " ";
  for(int i = 0; i < size.x * size.y; i++) {
    outStream << values[i] << " ";
  }

  outStream << "\n";
}

int * likhachev::Matrix::getValues() const
{
  return values;
}

likhachev::Point likhachev::Matrix::getSize() const
{
  return size;
}

int likhachev::countNonRepeatColumns(Matrix& matrix)
{
  likhachev::Point matrixSize = matrix.getSize();
  int * values = matrix.getValues();
  int totalCount = matrixSize.x;

  for( int i = 0; i < matrixSize.x; i++) {
    for (int j = 0; j < matrixSize.y - 1; j++) {
      if (values[matrixSize.x * j + i] == values[matrixSize.x * (j + 1) + i]) {
        totalCount--;
        break;
      }
    }
  }

  return totalCount;
}

void likhachev::changeMatrixWithSpiral(Matrix& matrix)
{
  Point direction(1, 0);
  Point position(-1, 0);
  Point submatrixSize = matrix.getSize();
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
      matrix.values[position.x + position.y * matrix.getSize().x] += counter; // Lavran [ToDo] : Обращение напрямую к переменным... не нравится, заменить
      counter++;
    }

    direction.x == 2 ? direction.x = -1 : direction.x++;
    direction.y == 2 ? direction.y = -1 : direction.y++;
  }
}


void likhachev::coutMatrix(Matrix& matrix) {
  Point matrixSize = matrix.getSize();
  for(int i = 0; i < matrixSize.x * matrixSize.y; i++) { // Lavran [ToDo] : Удалить
    if(matrix.values[i] < 10) {
      std::cout << "0";
    }
    std::cout << matrix.values[i] << " ";
    if((i + 1) % matrixSize.x == 0) {
      std::cout << "\n";
    }
  }
}

