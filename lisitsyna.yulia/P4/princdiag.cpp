#include "princdiag.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

	void lisitsyna::principal::arraay(int& rows, int& cols, std::ifstream& file, int*& values)
	{
		int count = 0;
		while (file.good())
		{
			file >> *(values + count);
			count++;
		}
		if (count < rows * cols)
		{
			std::cerr << "Insufficient number of elements" << "\n";
		}
	}
	void lisitsyna::principal::input_ar(std::ifstream& in, int* values, size_t sizeMatrix)
	{
		for (size_t i = 0; i < sizeMatrix; ++i)
		{
			in >> values[i];
			if (!in)
			{
				throw std::runtime_error("Incorrect input");
			}
		}
	}
	long long lisitsyna::principal::minSum(int rows, int cols, int* values)
	{
		int minS = std::numeric_limits< int >::max();
		for (int i = 1 - rows; i < rows; i++)
		{
			int curSum = 0;
			for (int j = 0; j < cols; j++)
			{
				if ((i + j) >= 0 && (i + j) < rows)
				{
					curSum += values[(i + j) * rows + j];
				}
			}
			minS = std::min(curSum, minS);
		}
		return minS;
	}
