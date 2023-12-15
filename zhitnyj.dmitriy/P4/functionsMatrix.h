#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

struct Matrix {
public:
    Matrix(int r, int c);
    ~Matrix();
    void readFromFile(std::ifstream &infile);
    int calculateMaxSumDiagonal() const;
    void transformMatrix();
    void writeToOutput(std::ofstream &outfile) const;

private:
    int **elements;
    int rows, cols;
};

#endif
