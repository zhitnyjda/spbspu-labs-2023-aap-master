#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "matrixActions.hpp"
#include "point.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Шnvalid number of arguments" << "\n";
    return 1;
  }

  int type = 0;
  try {
    type = std::stoi(argv[1], nullptr, 10);
    if (!(type == 1 || type == 2)) {
      std::cerr << "First parameter is out of range" << "\n";
      return 1;
    }
  } catch(std::logic_error const& e) {
    std::cerr << "First parameter is not a number" << "\n";
    return 1;
  }

  std::ifstream inStream;
  inStream.open(argv[2]);
  std::ofstream outStream;
  outStream.open(argv[3]);
  likhachev::Point matrixSize(0, 0);

  if (!(inStream.is_open() && outStream.is_open())) {
    std::cerr << "file was not found" << "\n";
    return 1;
  }

  inStream >> matrixSize.x >> matrixSize.y;
  if (!inStream) {
    std::cerr << "Input file is empty" << "\n";
    return 2;
  }
  if (matrixSize.x < 0 || matrixSize.y < 0) {
    std::cerr << "Wrong matrix size" << "\n";
    return 2;
  }

  int * matrixValues;
  if (type == 1) {
    int array[10000] = { 0 };
    matrixValues = array;
  } else  if (type == 2) {
    matrixValues = new int[matrixSize.x * matrixSize.y];
  }

  try {
    inputMatrixFromFile(matrixSize, inStream, matrixValues);
  } catch(std::runtime_error const& e) {
    std::cerr << e.what() << "\n";
    if (type == 2) {
      delete[] matrixValues;
    }
    return 2;
  }

  int countNRC = countNonRepeatColumns(matrixSize, matrixValues);
  changeMatrixWithSpiral(matrixSize, matrixValues);

  try {
    outStream << countNRC << "\n";
    outputMatrixToFile(matrixSize, outStream, matrixValues);
  } catch(std::runtime_error const& e) {
    std::cerr << e.what() << "\n";
    if (type == 2) {
      delete[] matrixValues;
    }
    return 1;
  }

  if (type == 2) {
    delete[] matrixValues;
  }
  return 0;
}
