#ifndef MATRIX_H
#define MATRIX_H
#include <cstdio>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();
    void loadFromFile(char* filename);
    void saveToFile(char* filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
