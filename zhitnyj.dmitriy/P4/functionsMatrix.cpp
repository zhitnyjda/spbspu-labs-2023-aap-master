#include "functionsMatrix.h"
#include <algorithm>
#include <stdexcept>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        throw std::invalid_argument("Invalid matrix size.");
    }
    try {
        elements = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            elements[i] = new int[cols];
        }
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("Failed to allocate memory for matrix.");
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

void Matrix::transformMatrix() {
    int decrement = 1;
    int startRow = 0, endRow = rows - 1;
    int startCol = 0, endCol = cols - 1;
    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; ++i) {
            elements[startRow][i] -= decrement++;
        }
        startRow++;
        for (int i = startRow; i <= endRow; ++i) {
            elements[i][endCol] -= decrement++;
        }
        endCol--;
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; --i) {
                elements[endRow][i] -= decrement++;
            }
            endRow--;
        }
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; --i) {
                elements[i][startCol] -= decrement++;
            }
            startCol++;
        }
    }
}

void Matrix::readFromFile(std::ifstream &infile) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(infile >> elements[i][j])) {
                throw std::runtime_error("Failed to read matrix data.");
            }
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
