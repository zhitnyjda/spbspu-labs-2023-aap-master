#include <iostream>
#include <exception>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char* argv[])
{
  std::string filenameIN = argv[2];
  std::string filenameOUT = argv[3];

  std::ifstream inStream;
  inStream.open(filenameIN); // Lavran : Заменить
  std::ofstream outStream;
  outStream.open(filenameOUT); // Lavran : Заменить
  int cols = 0;
  int rows = 0;

  inStream >> cols >> rows;
  likhachev::Matrix matrix = likhachev::Matrix(cols, rows);
  matrix.read(filenameIN);

  int countNRC = countNonRepeatColumns(matrix);

  std::cout << countNRC;
  
  return 0;
}
