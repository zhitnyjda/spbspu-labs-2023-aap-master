#include "functionsMatrix.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
    }

    char task = argv[1][0];
    if (task != '1' && task != '2') {
        std::cerr << "Invalid task number.\n";
        return 1;
    }

    std::ifstream infile(argv[2]);
    std::ofstream outfile(argv[3]);
    if (!infile || !outfile) {
        std::cerr << "File error.\n";
        return 1;
    }

    int rows, cols;
    infile >> rows >> cols;

    try {
        Matrix matrix(rows, cols);
        matrix.readFromFile(infile);

        if (task == '1') {
            int maxSum = matrix.calculateMaxSumDiagonal();
            outfile << "Max Sum Diagonal: " << maxSum << std::endl;
        } else {
            matrix.transformMatrix();
            matrix.writeToOutput(outfile);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        infile.close();
        outfile.close();
        return 1;
    }

    infile.close();
    outfile.close();
    return 0;
}
