#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix
{
public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    ~Matrix();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void processLFT();
    size_t processMAX();

private:
    size_t rows, cols;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
