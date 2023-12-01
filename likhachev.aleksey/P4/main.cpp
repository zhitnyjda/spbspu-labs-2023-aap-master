#include <iostream>
#include <exception>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char* argv[])
{
  argc = 3;
  argv[1][0] = '1';
  if (argc != 3) {
    if (argc < 3) {
      std::cerr << "Not enough arguments" << "\n";
    } else {
      std::cerr << "Too many arguments" << "\n";
    }
    
    return 1;
  }

  if (!(argv[1] == "1" || argv[1] == "2")) {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }

  // Lavran [ToDo] : Добавить обработчик для ошибки "First parameter is not a number"

  std::string filenameIN = "in.txt";
  std::string filenameOUT = "out.txt";

  std::ifstream inStream;
  inStream.open(filenameIN); // Lavran [ToDo] : Заменить на аргумент
  std::ofstream outStream;
  outStream.open(filenameOUT); // Lavran [ToDo] : Заменить на аргумент
  int cols = 0;
  int rows = 0;

  inStream >> cols >> rows;
  likhachev::Matrix matrix = likhachev::Matrix('2', cols, rows); // Lavran [ToDo] : Заменить "2" на аргумент
  matrix.readFromFile(filenameIN);

  int countNRC = countNonRepeatColumns(matrix);
  likhachev::changeMatrixWithSpiral(matrix);

  for(int i = 0; i < cols * rows; i++) { // Lavran [ToDo] : Заменить на вывод в файл ((Желательно создать функцию))
    if(matrix.values[i] < 10) {
      std::cout << "0";
    }
    std::cout << matrix.values[i] << " ";
    if((i + 1) % cols == 0) {
      std::cout << "\n";
    }
  }


  //std::cout << countNRC;
  
  return 0;
}
