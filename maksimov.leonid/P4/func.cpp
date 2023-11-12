#include "func.hpp"
#include <iostream>
#include <fstream>

namespace matrix
{
  void push_back(int*& arr, int& size, const int value)
  {
 	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
      newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
  }

  int* creatStaticMatrix(const std::string& text, size_t cols, size_t rows)
  {
	int* matrix = new int[rows * cols];
	for (int i = 0; i < (rows * cols); i++)
	{
	  matrix[i] = text[i] - '0';
	}
    return matrix;
  }

  bool matrixConditionCheck(const int* matrix, size_t cols, size_t rows)
  {
	int count = 0;
	int count_zero = 0;
	for (int i = 0; i < rows; i++)
	{
	  for (int j = 0; j < i; j++)
	  {
		if (matrix[(i * rows) + j] == 0)
		{
		  count++;
		}
		count_zero++;
	  }
	}
	return count == count_zero;
  }

  int printToFile(const std::string& name, const std::string& text)
  {
    std::ofstream fout(name);
	if (!fout.is_open())
	{
	  return 1;
	}
	fout << text;
	fout.close();
	return 0;
  }

  int readFile(const std::string& nameFile, size_t& cols_, size_t& rows_, std::string& text)
  {
	std::ifstream fin(nameFile);
	if (!fin.is_open())
	{
	  std::cerr << "fail file";
      return 1;
	}
	size_t cols;
	size_t rows;
	fin >> rows >> cols;
	int * matrix = new int[rows * cols];
	for (int i = 2; i < (rows * cols) + 2; i++)
	{
	  char temp;
	  fin >> temp;
	  text += temp;
	}
	rows_ = rows;
	cols_ = cols;
	fin.close();
	return 0;
  }
}