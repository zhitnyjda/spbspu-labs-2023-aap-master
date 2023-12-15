#include "functionsMatrix.h"
#include <stdexcept>

Matrix::Matrix(int r, int c, int arrayType) : rows(r), cols(c), arrayType(arrayType) {
    if (arrayType == 1) {
        if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
            throw std::invalid_argument("Invalid size for static array.");
        }
    } else if (arrayType == 2) {
        allocateDynamicArray();
    } else {
        throw std::invalid_argument("Invalid array type.");
    }
}

Matrix::~Matrix() {
    if (arrayType == 2) {
        deallocateDynamicArray();
    }
}

void Matrix::allocateDynamicArray() {
    dynamicArray = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols]{};
    }
}

void Matrix::deallocateDynamicArray() {
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}

void Matrix::readFromFile(std::ifstream &infile) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arrayType == 1) {
                infile >> staticArray[i][j];
            } else {
                infile >> dynamicArray[i][j];
            }
        }
    }
}

int Matrix::calculateMaxSumDiagonal() const {
    int maxSum = 0;
    // Реализация calculateMaxSumDiagonal
    return maxSum;
}

void Matrix::transformMatrix() {
    // Реализация transformMatrix
}

void Matrix::writeToOutput(std::ofstream &outfile) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = (arrayType == 1) ? staticArray[i][j] : dynamicArray[i][j];
            outfile << value << " ";
        }
        outfile << std::endl;
    }
}
