#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <fstream>

struct MatrixBase {
public:
    MatrixBase(int r, int c);
    virtual ~MatrixBase();
    void readFromFile(std::ifstream &infile);
    void writeToOutput(std::ofstream &outfile) const;

protected:
    int **elements;
    int rows, cols;
};

#endif
