#include "matr.h"
#include <iostream>
#include <fstream>
#include <cmath>
namespace sadofeva
{
	Matrix::Matrix(){}
	void Matrix::fl_ar(int& rows, int& cols, std::ifstream& file, int *& values)
	{
		int count = 0;
		while (file.good())
		{
		    file >>	*(values + count);
			count++;
		}
		if (count < rows * cols)
		{
			std::cerr << "Not" << "\n"; //кол-во элементов недостаточно
		}
	}
	int Matrix::locMax(int* values, int rows, int cols) // rows строки cols колонки
	{
		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 1; j < cols; j++)
			{
				if (*(values + (i * j)) > *(values + (i * j + 1)) && *(values + (i * j - 1)) < *(values + (i * j)))
				{
					count++;
				}
			}
		}
		return count;
	}
}
