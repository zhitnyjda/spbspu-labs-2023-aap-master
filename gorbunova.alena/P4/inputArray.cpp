#include "inputArray.hpp"
#include <iostream>
#include <fstream>

int gorbunova::readFixedSizeArray(const char* fileName, int(&fixedArray)[100][100], size_t& rows, size_t& cols)
{
  std::ifstream inputFile(fileName);
  if(!inputFile.is_open())
  {
    std::cerr << "Unable to open file" << fileName << "\n";
    return 2;
  }
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(inputFile >> fixedArray[i][j]))
      {
        std::cerr << "Invalid data\n";
        inputFile.close();
        return 2;
      }
    }
  }
  inputFile.close();
  return 0;
}
int gorbunova::readDynamicSizeArray(const char* fileName, int**& dynamicArray, size_t& rows, size_t& cols)
{
  std::ifstream inputFile(fileName);
  if(!inputFile.is_open())
  {
    std::cerr << "Unable to open file" << fileName << "\n";
    return 2;
  }
  dynamicArray = new int* [rows];
  for (int i = 0; i < rows; ++i)
  {
    dynamicArray[i] = new int[cols];
    for (int j = 0; j < cols; ++j)
    {
      if (!(inputFile >> dynamicArray[i][j]))
      {
        std::cerr << "Invalid data\n";
        inputFile.close();
        return 2;
      }
    }
  }
  inputFile.close();
  return 0;
}
int gorbunova::writeResultToFile(const char* fileName, int result)
{
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        outputFile << (result == 1 ? "true" : "false") << std::endl;
        outputFile.close();
    }
    else
    {
        std::cerr << "Unable to open output file " << fileName << std::endl;
        return 2;
    }
    return 0;
}
