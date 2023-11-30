#include <iostream>
#include <exception>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 3) {
    if (argc < 3) {
      std::cerr << "Not enough arguments" << "\n";
    } else {
      std::cerr << "Too many arguments" << "\n";
    }
    
    //return 1;
  }

  if (!(argv[1] == "1" || argv[1] == "2")) {
    if (argc < 3) {
      std::cerr << "Not enough arguments" << "\n"; // Lavran [ToDo] : Заменить на адекватную проверку (число вне радиуса / не число?)
    } else {
      std::cerr << "Too many arguments" << "\n";
    }

    //return 1;
  }

  std::string filenameIN = "in.txt";
  std::string filenameOUT = "out.txt";

  std::ifstream inStream;
  inStream.open(filenameIN); // Lavran [ToDo] : Заменить
  std::ofstream outStream;
  outStream.open(filenameOUT); // Lavran [ToDo] : Заменить
  int cols = 0;
  int rows = 0;

  inStream >> cols >> rows;
  likhachev::Matrix matrix = likhachev::Matrix('2', cols, rows);
  matrix.read(filenameIN);

  int countNRC = countNonRepeatColumns(matrix);
  likhachev::changeMatrixWithSpiral(matrix);

  for(int i = 0; i < cols * rows; i++) {
    std::cout << matrix.values[i] << " ";
    if((i + 1) % cols == 0) {
      std::cout << "\n";
    }
  }


  //std::cout << countNRC;
  
  return 0;
}
