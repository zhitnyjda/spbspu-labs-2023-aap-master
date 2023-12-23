#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void processLFT();
    size_t processMAX();

private:
    int rows, cols;
    int** data;

    void allocateMemory();
    void freeMemory();
};

#endif
