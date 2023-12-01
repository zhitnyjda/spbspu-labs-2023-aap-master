#include "matrix.hpp"
#include <fstream>
#include <iostream>

likhachev::Matrix::Matrix(char type, int mCols, int mRows)
{
  cols = mCols;
  rows = mRows;

  if (type == '1') {
    int array[10000] = { 0 };
    values = array;
  } else  if (type == '2') {
    int * array = new int[cols * rows];
    values = array;
  }
}

void likhachev::Matrix::read(std::string fileName)
{
  std::ifstream inStream;
  inStream.open(fileName);

  inStream >> values[0] >> values[0];

  for(int i = 0; i < cols * rows; i++) {
    inStream >> values[i];
  }
}

int * likhachev::Matrix::getValues() const
{
  return values;
}

int likhachev::Matrix::getCols() const
{
  return cols;
}

int likhachev::Matrix::getRows() const
{
  return rows;
}

int likhachev::countNonRepeatColumns(Matrix matrix)
{

  int cols = matrix.getCols();
  int rows = matrix.getRows();
  int * values = matrix.getValues();
  int totalCount = cols;

  for( int i = 0; i < rows; i++) {
    for (int j = 0; j < cols - 1; j++) {
      if (values[cols * j + i] == values[cols * (j + 1) + i]) {
        totalCount--;
        break;
      }
    }
  }

  return totalCount;
}

void likhachev::changeMatrixWithSpiral(Matrix& matrix)
{
  int direction[2] = {1, 0};
  int position[2] = {-1, 0};
  int colsSteps = matrix.getCols();
  int rowsSteps = matrix.getRows();
  int counter = 1;
  int steps = 0;
  while (colsSteps > 0 && rowsSteps > 0) {
    if (direction[0] % 2) {
      steps = colsSteps;
      rowsSteps--;
    } else {
      steps = rowsSteps;
      colsSteps--;
    }

    for(int j = 0; j < steps; j++) {
      position[0] += direction[0] % 2;
      position[1] += direction[1] % 2;
      std::cout << " | " << "Position: " << position[0] << " " << position[1] << "\n";
      matrix.values[position[0] + position[1] * matrix.getCols()] += counter;
      counter++;
    }

    direction[0] == 2 ? direction[0] = -1 : direction[0]++;
    direction[1] == 2 ? direction[1] = -1 : direction[1]++;
    
    std::cout << "iteration: " << rowsSteps << " " << colsSteps << "\n";
  }
}

