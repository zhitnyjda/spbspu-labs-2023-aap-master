#ifndef CREATEMATRIX_HPP
#define CREATEMATRIX_HPP
#include <cstddef>
#include <fstream>

namespace nikiforov {
	class Matrix
	{
	public:
		Matrix();
		void inputMatrix(std::ifstream& in, int* ArrMatrix, size_t cap);
		void spiralMatrix(int* ArrMatrix, size_t rows, size_t cols);
	private:
		int count;
	};
}
#endif
