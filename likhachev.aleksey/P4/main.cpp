#include <iostream>
#include <exception>
#include <fstream>
#include <string>
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

  int type = 0;
  try {
    type = std::stoi(argv[1], nullptr, 10);
    if (!(type == 1 || type == 2 || true)) {
      std::cerr << "First parameter is out of range" << "\n";
      return 1;
    }
  } catch(std::logic_error const& e) {
    std::cerr << "First parameter is not a number" << "\n";
    // return 1; 
  }

  std::string filenameIN = "in.txt";
  std::string filenameOUT = "out.txt";
  
  std::ifstream inStream;
  inStream.open(filenameIN); // Lavran [ToDo] : Заменить на аргумент
  std::ofstream outStream;
  outStream.open(filenameOUT); // Lavran [ToDo] : Заменить на аргумент
  likhachev::Point matrixSize(0, 0);

  if (!(inStream.is_open() && outStream.is_open())) {
    std::cerr << "file was not found" << "\n";
    return 1;
  }

  inStream >> matrixSize.x >> matrixSize.y;
  if (matrixSize.x < 1 || matrixSize.y < 1) {
    std::cerr << "Wrong matrix size" << "\n";
    return 1;
  }

  likhachev::Matrix matrix = likhachev::Matrix('2', matrixSize.x, matrixSize.y);
  try {
    matrix.inputFromFile(inStream);
  } catch(std::runtime_error const& e) {
    std::cerr << e.what() << "\n";
    return 1; 
  }

  int countNRC = countNonRepeatColumns(matrix);
  changeMatrixWithSpiral(matrix);

  std::cout << countNRC << "\n"; // Lavran [ToDo] : Удалить
  likhachev::coutMatrix(matrix);
  
  outStream << countNRC << "\n";
  try {
    matrix.outputToFile(outStream);
  } catch(std::runtime_error const& e) {
    std::cerr << e.what() << "\n";
    return 1; 
  }
  
  return 0;
}
