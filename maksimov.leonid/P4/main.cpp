#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "func.cpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cout << "argc != 4";
	return 1;
  }
  try
  {
    int num = std::stoi(argv[1]);
	if (num == 1)
	{
	  size_t cols;
	  size_t rows;
	  std::string textFile;
	  if (matrix::readFile(argv[2], cols, rows, textFile))
	  {
		return 1;
	  }
	  int * matrix = matrix::creatStaticMatrix(textFile, cols, rows);
	  if (matrix::matrixConditionCheck(matrix, cols, rows))
	  {
		if (matrix::printToFile(argv[3], "true"))
		{
		  return 1;
		}
	  }
	  else
	  {
		if (matrix::printToFile(argv[3], "false"))
		{
		  return 1;
		}
	  }
	  delete[] matrix;
	}
	else if (num == 2)
	{
	  std::ifstream file(argv[2]);
	  if (!file.is_open())
	  {
		std::cout << "fail file";
		return 1;
	  }
	  int size = 0;
	  int * matrix = new int[size];
	  while (!file.eof())
	  {
		int temp;
		file >> temp;
		matrix::push_back(matrix, size, temp);
	  }
	  for (int i = 0; i < size; i++)
	  {
		std::cout << matrix[i] << "\n";
	  }
	}
  }
  catch (const std::invalid_argument &)
  {
    std::cout << "argv[0] not int";
	return 1;
  }
} 