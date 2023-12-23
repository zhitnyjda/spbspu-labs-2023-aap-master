#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();
    void loadFromFile(const char* filename);
    void saveToFile(const char* filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
