#include <iostream>
#include <exception>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 3) {
    if (argc < 3) {
      std::cerr << "Not enough arguments";
    } else {
      std::cerr << "Too many arguments";
    }
    
    return 1;
  }

  if (!(argv[1] == "1" || argv[1] == "2")) {
    if (argc < 3) {
      std::cerr << "Not enough arguments"; // Lavran [ToDo] : Заменить на адекватную проверку (число вне радиуса / не число?)
    } else {
      std::cerr << "Too many arguments";
    }

    return 1;
  }

  std::string filenameIN = argv[2];
  std::string filenameOUT = argv[3];

  std::ifstream inStream;
  inStream.open(filenameIN); // Lavran [ToDo] : Заменить
  std::ofstream outStream;
  outStream.open(filenameOUT); // Lavran [ToDo] : Заменить
  int cols = 0;
  int rows = 0;

  inStream >> cols >> rows;
  likhachev::Matrix matrix = likhachev::Matrix(argv[1][0], cols, rows);
  matrix.read(filenameIN);

  int countNRC = countNonRepeatColumns(matrix);

  std::cout << countNRC;
  
  return 0;
}
