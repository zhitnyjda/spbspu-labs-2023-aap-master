#ifndef PRINCDIAG_HPP
#define PRINCDIAG_HPP
#include <fstream>

namespace lisitsyna
{
    struct principal
    {
    public:
        size_t input_ar(std::ifstream& in, int* values, size_t sizeMatrix);
	long long minSum(int rows, int cols, int* values);
    private:
        int rows;
        int cols;
        int* values;
        size_t sizeMatrix;
    };
}

#endif
