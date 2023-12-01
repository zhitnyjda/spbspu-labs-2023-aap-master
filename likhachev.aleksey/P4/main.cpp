#include <iostream>
#include <exception>
#include <fstream>
#include "matrix.cpp"
#include "matrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 3 && false) {
    if (argc < 3) {
      std::cerr << "Not enough arguments" << "\n";
    } else {
      std::cerr << "Too many arguments" << "\n";
    }
    
    return 1;
  }

  if (!(argv[1] == "1" || argv[1] == "2" || true)) {
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
  likhachev::Point matrixSize(0, 0);

  inStream >> matrixSize.x >> matrixSize.y;
  likhachev::Matrix matrix = likhachev::Matrix('2', matrixSize.x, matrixSize.y);
  matrix.inputFromFile(inStream);

  int countNRC = countNonRepeatColumns(matrix);
  changeMatrixWithSpiral(matrix);

  std::cout << countNRC << "\n"; // Lavran [ToDo] : Удалить
  for(int i = 0; i < matrixSize.x * matrixSize.y; i++) { // Lavran [ToDo] : Удалить
    if(matrix.values[i] < 10) {
      std::cout << "0";
    }
    std::cout << matrix.values[i] << " ";
    if((i + 1) % matrixSize.x == 0) {
      std::cout << "\n";
    }
  }
  
  outStream << countNRC << "\n";
  matrix.outputToFile(outStream);
  
  return 0;
}
