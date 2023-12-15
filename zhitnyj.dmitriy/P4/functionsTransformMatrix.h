#ifndef FUNCTIONS_MAX_SUM_DIAGONAL_H
#define FUNCTIONS_MAX_SUM_DIAGONAL_H

#include <fstream>

struct Matrix {
public:
    Matrix(int r, int c);
    ~Matrix();
    void readFromFile(std::ifstream &infile);
    int calculateMaxSumDiagonal() const;
    void writeToOutput(std::ofstream &outfile) const;
    void transformMatrix();

private:
    int **elements;
    int rows, cols;
};

#endif
