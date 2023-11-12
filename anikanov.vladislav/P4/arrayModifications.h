#ifndef ARRAYMODIFICATIONS_H
#define ARRAYMODIFICATIONS_H
#include <iosfwd>

template<typename arrayType>
void spiralIncrease(arrayType *array, int n, int m);

template<typename arrayType>
void inputArray(std::istream &, arrayType *array, int n, int m);

template<typename arrayType>
void printArray(std::ostream &, arrayType array, int n, int m);

#endif //ARRAYMODIFICATIONS_H
