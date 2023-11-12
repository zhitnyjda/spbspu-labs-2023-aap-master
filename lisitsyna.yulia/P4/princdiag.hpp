#ifndef PRINCDIAG_HPP
#define PRINCDIAG_HPP
#include <fstream>

namespace lisitsyna
{
    struct principal
    {
    public:
        void arraay(int& rows, int& cols, std::ifstream& file, int*& values);
        long long minSum(int rows, int cols, int* values);
        void input_ar(std::ifstream& in, int* values, size_t sizeMatrix);
    private:
        int rows;
        int cols;
        int* values;
        size_t sizeMatrix;
    };
}

#endif
