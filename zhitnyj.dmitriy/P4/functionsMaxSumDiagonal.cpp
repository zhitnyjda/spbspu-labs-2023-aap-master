#include "functionsMatrix.h"
#include <algorithm>
#include <stdexcept>

void Matrix::readFromFile(std::ifstream &infile) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> elements[i][j];
        }
    }
}

int Matrix::calculateMaxSumDiagonal() const {
    int maxSum = 0;
    for (int d = 1; d < cols; ++d) {
        int sum = 0;
        for (int i = 0; i < rows && d + i < cols; ++i) {
            sum += elements[i][d + i];
        }
        maxSum = std::max(maxSum, sum);
    }
    for (int d = 1; d < rows; ++d) {
        int sum = 0;
        for (int i = 0; i < cols && d + i < rows; ++i) {
            sum += elements[d + i][i];
        }
        maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}

void Matrix::writeToOutput(std::ofstream &outfile) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outfile << elements[i][j] << " ";
        }
        outfile << std::endl;
    }
}
