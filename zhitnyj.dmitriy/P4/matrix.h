#ifndef MATRIX_H
#define MATRIX_H
#include <cstdio>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols, int num);
    ~Matrix();
    void loadFromFile(char* filename);
    void saveToFile(char* filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols, num;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
