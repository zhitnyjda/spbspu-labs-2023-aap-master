#ifndef MATRIX_H
#define MATRIX_H
#include <cstdio>

class Matrix
{
public:
    Matrix(int rows = 0, int cols = 0, int num = 2);
    ~Matrix();
    void loadFromFile(char* filename);
    void saveToFile(char* filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols, num_;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
