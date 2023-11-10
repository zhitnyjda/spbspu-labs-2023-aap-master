#include "Funcs.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
namespace seryj
{
	std::ifstream input;
	std::ofstream output;
	int fillArguments(int args, const char** argv)
	{
		if (args > 4)
			throw (std::invalid_argument("Too much arguments"));
		if (args < 4)
			throw (std::invalid_argument("Not enough elements"));
		input.open(argv[2]);
		output.open(argv[3]);
		int n = std::strtoll(argv[1], nullptr, 10);
		if (n < 1 || n>2)
			throw(std::invalid_argument("Invalid argument"));
		return n;
	}
	int read()
	{
		int val = 0;
		if (input.is_open() && input)
			input >> val;
		else if (!input.is_open())
			throw std::invalid_argument("Cant open input.txt");
		if (!input)
			throw std::logic_error("Input error");
		return val;
	}
	void Matrix::fillArray()
	{
		int count = 0;
		while(input.good())
		{
		  *(values + count) = read();
		  count++;
		}
		if(count < line*column)
			throw std::logic_error("Not enough elements");
	}
	void Matrix::printAvgOfNeigbours()const
	{
		if (output.is_open())
		{
		output << line << " ";
		output << column << " ";
		for (int i = 0; i < line; i++)
			for (int j = 0; j < column; j++)
			{
				output << findAverageOfNeighbours(i, j) << " ";
			}
     	}
		else throw (std::invalid_argument("Cant open output file"));
		output.close();
	}
	double Matrix::findAverageOfNeighbours(int curr_line, int curr_column) const
	{
		int count = 0;
		double sum = 0;
		int max_line = line;
		int max_column = column;
		for (int i = curr_line - 1; i <= curr_line + 1; i++)
			for (int j = curr_column - 1;j <= curr_column + 1; j++)
			{
				if (j >= 0 && j < max_column && i >= 0 && i < max_line)
				{
					sum += *(values + i * max_line + j);
					count++;
				}
			}
		count--;
		sum -= *(values + curr_line * max_line + curr_column);
		if (count > 0)
			return round(sum / count * 10) / 10;
		else return 0;
	}
}
