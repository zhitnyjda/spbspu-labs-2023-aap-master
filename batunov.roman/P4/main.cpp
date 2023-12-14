#include <iostream>
#include <fstream>
#include <string>

//функция - считать двумерный массива из файла
int** readMatrixFromFile(const std::string& filename, int& rows, int& cols) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Do not open the input file.");
    }
    inputFile >> rows >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();
    return matrix;
}

//функция - освобожденип памяти, выделенной под двумерный массив
void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//функция - логика (вариант)
int longestCombin(int** matrix, int rows, int cols) {
    int longestCombinRow = -1;
    int longestCombinLength = 0;
    for (int i = 0; i < rows; i++)
    {
        int currentCombinLength = 1;
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == matrix[i][j - 1])
            {
                currentCombinLength++;
            }
            else {
                if (currentCombinLength > longestCombinLength)
                {
                    longestCombinRow = i;
                    longestCombinLength = currentCombinLength;
                }
                currentCombinLength = 1;
            }
        }
        if (currentCombinLength > longestCombinLength)
        {
            longestCombinRow = i;
            longestCombinLength = currentCombinLength;
        }
    }
    return longestCombinRow + 1;
}

//функция - запись результата в файл
void writeResultToFile(const std::string& filename, int result)
{
    std::ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Do not open the output file.");
    }
    outputFile << result;
    outputFile.close();
}

//майн, обработки исключений
int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments." << std::endl;
        return 1;
    }
    int taskNumber;
    try
    {
        taskNumber = std::stoi(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << "Wrong task number." << std::endl;
        return 1;
    }
    std::string inputFilename = argv[2];
    std::string outputFilename = argv[3];
    int** matrix;
    int rows, cols;
    try
    {
        matrix = readMatrixFromFile(inputFilename, rows, cols);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error reading input file: " << e.what() << std::endl;
        return 2;
    }
    int result;
    if (taskNumber == 1)
    {
        result = longestCombin(matrix, rows, cols);
    }
    try
    {
        writeResultToFile(outputFilename, result);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error writing output file: " << e.what() << std::endl;
        return 2;
    }
    freeMatrix(matrix, rows);
    return 0;
}
