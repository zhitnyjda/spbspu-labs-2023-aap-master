#ifndef FUNCS_HPP
#define FUNCS_HPP
namespace seryj
{
	int fillArguments(int, const char* []);
	int read();
	class Matrix
	{
	public:
		int line;
		int column;
		int* values;
		void fillArray();
		void printAvgOfNeigbours()const;
	private:
		double findAverageOfNeighbours(int,int)const;
	};
}
#endif
