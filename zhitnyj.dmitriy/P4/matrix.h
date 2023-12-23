#ifndef MATRIX_H
#define MATRIX_H
#include <memory>
#include <cstdio>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& matrix);
    ~Matrix();
    void loadFromFile(char* filename);
    void saveToFile(char* filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols;
    std::unique_ptr<int[]> data;

    void allocateMemory();
    void freeMemory();
};

#endif
